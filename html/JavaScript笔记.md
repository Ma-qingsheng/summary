<h1>
    全干工程师（JavaScript）学习笔记
</h1>

```
<script type="text/javascript" src="??/ ??.js"> </script>
```



JS中严格区分大小写！|  每个语句原则上使用分号结尾

onmouseover  鼠标移入      onmouseout鼠标移出	

alert("")在浏览器中弹出来一个警告框

document.write("")向body中输出一个内容

console.log（“”）向控制台输出一个内容

var  声明变量。

---------------------------------------------------------------------------------------

标识符： 在JS中所有可以自主命名的都是标识符。（变量名，函数名 属性名）

<ul>
    <li>字母数字_$</li>
	<li>不能数字开头</li>
    <li>不能是ES中的关键字和保留字</li>
	<li>驼峰命名法：首字母小写，每个单词开头字母大写，其余字母小写</li>
    <LI>理论上所有的UTF-8中的东西都可以用</LI>
</ul>
----------------

六种数据类型（原始值）（typeof可以检查数据类型）

1. string 字符串

2. number 数值（所有数值都是这个类型 超过最大值返回infinity无穷 NaN表示不是一个数字 精确度不高）
3. boolean 布尔值（真true假false，逻辑判断）
4. Null 空值
5. Undefined 未定义
6. Object 对象

<!--加上引号为字符串，，不加为变量-->

数据转化

1. 调用被转化的toString()方法（不会影响原变量，会将转换的结果返回）
2. 调用String函数，并将被转化的数据

##### 对象

在 JavaScript 中，几乎“所有事物”都是对象。

- 布尔是对象（如果用 *new* 关键词定义）
- 数字是对象（如果用 *new* 关键词定义）
- 字符串是对象（如果用 *new* 关键词定义）
- 日期永远都是对象
- 算术永远都是对象
- 正则表达式永远都是对象
- 数组永远都是对象
- 函数永远都是对象
- 对象永远都是对象

所有 JavaScript 值，除了原始值，都是对象。

## 对象方法

方法是可以在对象上执行的*动作*。

对象属性可以是原始值、其他对象以及函数。

*对象方法*是包含*函数定义*的对象属性。

#   JQuery

* $函数是全局的且$==jQuery。window.$==window.jQuery==jQuery为true。若其他 JavaScript 框架也使用 $ 符号作为简写怎么办？法一：用jQuery代替。法二：使用noConflict() 方法释放对 $ 标识符的控制。

```
var jq = $.noConflict();
jq(document).ready(function(){
  jq("button").click(function(){
    jq("p").text("jQuery 仍然在工作呐!");
  });
});
```

*  分清js原生对象和jq对象,写的时候容易混用，用原生对象就去调用jq方法了。原生对象无法调用后者方法，调用先转换，转换方式$(需转原生对象)就可以调用jq方法了。

```
this.html()//报错:Uncaught TypeError: this.html is not a function
 $(this).html()//把原生对象的this转为jq对象
var oTest = document.getElementById("test");
    //其他js对象转jq对象
    console.log($(oTest))
console.log($("#test").get(0))//get(0)jq对象集合里获取的第一个对象值

```

*  jq选择器常用共8种，可根据css选择器，对比记忆呀。另外，选择器中可使用css中的伪类选择器

  ```
  //1.id选择器
  $("#box").html()  // 用 #号
  //2.类选择器
  $(".box").html   //用 . 号
  //3.标签选择器
  $("div").html   //直接给标签名
  //4.多元素选择器
  $("#box,.box,div").html();  // 几种选择器组合
  //5.后代选择器
  $("#box p").html()  // 用空格隔开
  //6.子元素选择器
  $("#box > p").html() ; // 用> 隔开
  //7.伪类选择器
  $("p:nth-child(2)").css("background-color"))
  //8.属性选择器
  $("input[value=men]") ; //找 value=men的input元素
  $("input[value*=men]") ; //找 value里面包含men的input元素
  $("input[value^=men]") ; //找 value里面以men开头的input元素
  $("input[value$=men]") ; //找 value里面以men结尾的input元素
  ```

  