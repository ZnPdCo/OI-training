try:
    from flask import Flask, request  # 导入Flask库和request对象
    import sys
    import threading
    import time
    import json
    import os
    import signal
    import webbrowser
except Exception as e:
    import os
    os.system("pip install flask threading webbrowser")

# 检查命令行参数数量
if len(sys.argv) not in [3, 4]:
    print("Usage: python script.py <file_path> <arg1> [arg2]")
    sys.exit(1)

# 读取文件内容
with open(sys.argv[1], "r", encoding='UTF-8') as f:
    text = f.read()

# 如果不存在配置文件，则创建一个默认配置文件
default_config_path = 'C:/gmbt.json'
default_config_content = 'https://gmoj.net/senior/#main/submit/{}/{}'
if not os.path.exists(default_config_path):
    with open(default_config_path, "w", encoding='UTF-8') as f:
        f.write(default_config_content)

# 读取配置文件内容
with open(default_config_path, "r", encoding='UTF-8') as f:
    tamp = f.read()

# 创建Flask应用
app = Flask(__name__)

# 定义用于关闭应用的函数
def shutdown(ti, text, pid):
    time.sleep(ti)
    print(text)
    os.kill(pid, signal.SIGINT)

# 定义路由处理函数
@app.route('/', methods=['POST'])
def index():
    t = threading.Thread(target=shutdown, args=(1, 'ok', os.getpid(),))
    t.start()
    return text

# 主函数入口
if __name__ == '__main__':
    # 启动一个线程，用于在一定时间后关闭应用
    t = threading.Thread(target=shutdown, args=(10, 'timeout', os.getpid(),))
    t.start()
    # 根据命令行参数数量打开浏览器并访问指定URL
    if len(sys.argv) == 3:
        webbrowser.open(tamp.format(sys.argv[2], '')+'?code=server')
    if len(sys.argv) == 4:
        webbrowser.open(tamp.format(sys.argv[2], sys.argv[3])+'?code=server')
    # 运行Flask应用
    app.run(port=20419)
