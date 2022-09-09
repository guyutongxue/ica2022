# 计算概论 A

这里是《计算概论 A》（董豪班）信息站。

<div class="action-container">
    <a href="/ide/" class="action bg1">开发环境相关</a>
    <a href="/grid/" class="action bg7">编程网格相关</a>
    <a href="/cpp/" class="action bg2">C++ 相关</a>
    <a href="/errata/" class="action bg3">课件勘误</a>
    <a href="/answer/" class="action bg4">习题解答</a>
</div>

## 快捷链接

<div class="action-container">
    <a
      href="https://programming.pku.edu.cn/course/0b0ead5e1550494cb060fca75d9e2604/"
      class="action bg5"
      target="_blank" rel="noreferrer"
    >
      编程网格
    </a>
    <a 
      href="https://learn-cpp.tk"
      class="action bg6"
      target="_blank" rel="noreferrer"
    >
      C++ 教程
    </a>
</div>

此站点由谷雨同学制作。如果有任何问题或想要补充的内容，请直接私戳谷雨助教，或者给 `guyutongxue@163.com` 发邮件。

<style>
    /* https://uigradients.com/ */
.action-container {
    display: grid;
    grid-template-columns: 1fr 1fr;
    gap: 1rem;
}
@media (min-width: 576px) {
    .action-container {
        grid-template-columns: 1fr 1fr 1fr;
    }
}
@media (min-width: 992px) {
    .action-container {
        grid-template-columns: 1fr 1fr 1fr 1fr;
    }
}
a.action {
    display: block;
    height: 5rem;
    border-radius: 1rem;
    padding: 1rem;
    font-weight: unset;
    color: white;
    transition: transform 0.2s;
}
a.action:hover {
    color: white;
    transform: scale(110%);
}
.bg1 {
    background: linear-gradient(to right, #73c8a9, #373b44);
}
.bg2 {
    background: linear-gradient(to right, #fe8c00, #f83600);
}
.bg3 {
    background: linear-gradient(to right, #add100, #7b920a);
}
.bg4 {
    background: linear-gradient(to right, #9d50bb, #6e48aa);
}
.bg5 {
    background: linear-gradient(to right, #de6262, #ffb88c); 
}
.bg6 {
    background: linear-gradient(to right, #b993d6, #8ca6db);
}
.bg7 {
    background: linear-gradient(to right, #e9d362, #333333);
}
</style>
