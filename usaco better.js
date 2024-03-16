$(`<button style="margin-bottom:6px;" type="button" id="fanyi">翻译</button>`).insertBefore('#probtext-text')

$(`#fanyi`).click(function() {
    $.ajax({
        type: "GET",
        url: location.href,
        async: false,
        success: function(data) {
            text = $(data).find('#probtext-text').html()
            texts = text.split('$$')
            res = ""
            tex = [], btex = []
            tex2res = '小牛顿里叶欧拉变换', btex2res = '大牛顿里叶欧拉变换'
            for(let i = 0; i < texts.length; i++) {
                if(i % 2 == 0) res += texts[i];
                else btex.push(texts[i]), res += btex2res;
            }
            text = res
            texts = text.split('$')
            res = ""
            for(let i = 0; i < texts.length; i++) {
                if(i % 2 == 0) res += texts[i];
                else tex.push(texts[i]), res += tex2res;
            }
            text = res
            
            // 翻译
            
            texts = text.split(btex2res)
            res = ""
            for(let i = 0; i < texts.length; i++) {
                res += texts[i];
                if(i < btex.length) res += '$$' + btex[i] + '$$'
            }
            text = res
            texts = text.split(tex2res)
            res = ""
            for(let i = 0; i < texts.length; i++) {
                res += texts[i];
                if(i < tex.length) res += '$' + tex[i] + '$'
            }
            text = res

            if($('#fanyi_result').length == 0)
                $(`<div align="left" id="fanyi_result" class="problem-text mathjax" style="width:800px; padding-top:10px;"></div>`).insertBefore('#probtext-text')
            $('#fanyi_result').html(text);
            MathJax.Hub.Queue(["Typeset", MathJax.Hub]);
        },
        error: function(xhr, statusText, error) {}
    });
})


$('#baidu_translate_input').val('are you ok')
$('#translate-button').click()
setTimeout(function() {$('.ordinary-output.target-output.clearfix').text()}, 2000)