<h1>   git学习情况报告</h1>

git： 分布式版本控制软件。git保存的是文件的差异，时多人一起工作时更便捷。



<h3>
    git怎么用，一般分四步进行
</h3>
<ol TYPE=a>
    <li>建立远程仓库</li>
    <li>建立本地仓库,并与远程仓库绑定</li>
    <li>在本地仓库进行自己工作</li>
    <li>将本地仓库推送到远程仓库</li>
</ol>

a

在自己的账号中新建文件仓库，在仓库中必须包含一个readme.md文件。

b

自己建立的文件夹作为本地仓库，在文件夹中运行Git Bush Here，使用git remote add origin  <htpps>指令进行与远程仓库的联系。

d

推送至远程仓库时需要用到git add  ,  git commit -m"text" , git pull ,  git push。

其中git add . 上传所有文件，git add file 上传某个特定的文件。值得注意的是在多人同时编辑时，push之前需要进行pull指令，不然可能推送失败，并且git会帮助我们自动解决冲突，但是有的冲突需要自己动手来解决。



<h3>
    git指令
</h3>

git status 指令可以查看当前文件状态，修改上传，暂存等。

git add . 将本地所有新增文件提交到本地缓存区 

git add [file] 将本地某个新增文件提交到本地缓存区

ls 查看文档。

git log指令看到文件的修改历程。

echo > file 指令建立新的文件。

git remote –v  查看远程仓库地址。

git clone http||ssh 克隆一份代码到本地仓库 。

...... 	



<h3>
    常用命令流程图
</h3>



![13932133-1b0b15428acbd89e.png (840×593)](https://upload-images.jianshu.io/upload_images/13932133-1b0b15428acbd89e.png?imageMogr2/auto-orient/strip|imageView2/2/w/840/format/webp)



<h3>
    更好使用git
</h3>









<h3>
    git注意事项</h3>

<ul>
    <li>每次提交代码前使用 git status 查看本地修改状态</li>
    <li>新增的文件使用 git add [file] 或者 git add . 添加文件</li>
    <li>提交前 请使用 git pull 进行</li>
    <li>多沟通，不要随意将别人的代码删除</li>
</ul>

<h3>
    心得
</h3>

​		外网的东西确实好，但是外网加载的太慢了，那么多英语单词还得用翻译看看，中国没有这样的牛人来建立个比git更厉害的东西么。。今后学习的都东西需要向git中进行记录，在三院组织中多看看，在里面多学学，不能一直打游戏看电视，让生活更有意义点。还要学好英语。







