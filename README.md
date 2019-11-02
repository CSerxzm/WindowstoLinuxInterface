<pre>
step:	
	make
	PT=$(readlink -f ./bin);export PATH="${PT}:$PATH"


DIR
列出文件夹
<code>	DIR directory
</code>
	
RD
删除文件夹
	RD directory
	
CD

MD
创建文件夹
	MD directory1 [directory2]
	
DEL
删除文件
	DEL filename1 [filename2]
REN
重命名文件/文件夹
    RENAME srcfilename/srcdirectory dstfilename/dstdirectory
	
XCOPY
复制文件夹
	XCOPY srcdirectory dstdirectory
	
PROMPT

SORT
文本升序排序
	SORT filename
TYPE
显示文本内容
    TYPE filename
COPY
复制文件
	XCOPY srcfilename dstfilename
	
COMP
比较两个文件的内容
    COMP filename1 filename2

DATE
日期显示
	DATE
	
TIME
时间显示
	TIME
	
MORE
逐行显示
	MORE filename
	回车为下一行
	空格为下一页
	q：退出显示
	
FIND
在文件中查找字符串
	FIND filename string
</pre>

