// 一个小爬虫

# coding=utf-8
import requests
import re

# pyinstaller -D -p F:\ccddPY\pycode\Xtext -i logo.ico s4TianYa.py


def getHtmlContent(url):
    headers = {
        "User-Agent":"Mozilla/5.0 (Windows NT 10.0; Win64; x64) AppleWebKit/537.36 (KHTML, like Gecko) Chrome/88.0.4324.182 Safari/537.36"

    }
    htmlContent = requests.get(url=url,headers=headers)
    return htmlContent

def saveHtmlContent(htmlContent):
    file = open(r'F:\ccddPY\pycode\All21\studySc\studySAVE\s2\tianYa.html','w')
    file.write(htmlContent.text)
    file.close()

def saveTextHost(text):
    file = open('F:\ccddPY\pycode\All21\studySc\studySAVE\s2\\tianYa.txt','w')
    file.write(text)
    file.close()

def replaceStr(txtString):
    partten = re.compile('<br>|\n\n')
    stringTxt = partten.sub('',txtString)
    return stringTxt

def getMainTextHost(htmlContent):
    textReg2 = re.compile('<div class="bbs-content clearfix">(.+?)</div>',re.S)
    textStartString = re.findall(textReg2,htmlContent.text) # --------------------
    textReg = re.compile('class="bbs-content">(.+?)</div>',re.S)
    textList = re.findall(textReg,htmlContent.text)
    txt = ''
    for textLL in textStartString:
        txt = txt + str(textLL)
    for textL in textList:
        txt = txt + str(textL)
    txt = replaceStr(txt)
    return txt

if __name__ == '__main__':
    # url = 'http://bbs.tianya.cn/post-no05-523301-1.shtml'
    print('输入链接')
    url = input()
    htmlContent = getHtmlContent(url)
    saveHtmlContent(htmlContent)
    print('状态码'+str(htmlContent.status_code))
    text = getMainTextHost(htmlContent)
    saveTextHost(text)

