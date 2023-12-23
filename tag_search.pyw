import os
import difflib
import tkinter as tk
import webbrowser

def string_similar(s1, s2):
    return difflib.SequenceMatcher(None, s1, s2).quick_ratio()

def get_tags(file_path):
    tags = []
    with open(file_path, 'r', encoding='utf-8') as file:
        lines = file.readlines()
        for line in lines:
            if line.startswith(' * @tag:'):
                tags.extend(line.strip().split('#')[1:])
    return tags

def search_files_by_tag(directory, key):
    matching_files = []
    for root, dirs, files in os.walk(directory):
        for file in files:
            if file.endswith('.cpp'):
                file_path = os.path.join(root, file)
                tags = get_tags(file_path)
                max_ratio = 0
                for tag in tags:
                    max_ratio = max(max_ratio, string_similar(key, tag))
                if max_ratio > 0.5:
                    matching_files.append({'file_path': file_path, 'ratio': max_ratio})
    matching_files.sort(key=lambda x: x['ratio'], reverse=True)
    return matching_files

def search_button_click(event):
    tag = entry.get()
    matching_files = search_files_by_tag('.', tag)
    result_text.delete('1.0', tk.END)
    for file in matching_files:
        result_text.insert(tk.END, f"{file['file_path']} (相似度: {file['ratio']})\n")
        
    # 链接文件列表中的文件名和打开文件的函数
    for tag in result_text.tag_names():
        if tag.startswith("file_link"):
            result_text.tag_delete(tag)
    
    for i, file in enumerate(matching_files):
        start = f"{i + 1}.0"
        end = f"{i + 1}.{len(file['file_path'])}"
        result_text.tag_configure(f"file_link{i}", foreground="blue", underline=True)
        result_text.tag_bind(f"file_link{i}", "<Button-1>", lambda event, path=file['file_path']: open_file(path))
        result_text.tag_add(f"file_link{i}", start, end)
    
def open_file(file_path):
    webbrowser.open(file_path)

window = tk.Tk()
window.title("文件搜索")
window.geometry('400x300')

label = tk.Label(window, text="请输入要搜索的标签:")
label.pack()

entry = tk.Entry(window)
entry.bind("<KeyRelease>", search_button_click)
entry.pack()

result_text = tk.Text(window)
result_text.pack()

window.mainloop()
