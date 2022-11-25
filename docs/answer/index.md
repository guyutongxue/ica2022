# 习题答案

此答案不定期更新。为了保证更好的学习质量，请不要直接抄写。

> 我尽可能提供两种版本的答案，“C++ 风格”和“计概 A 风格”。“计概 A 风格”是在授课范围内、易于理解的代码；“C++ 风格”则倾向于工程化、标准化的高水平代码。建议无基础同学优先阅读“计概 A 风格”，“C++ 风格”可作为拓展提高。

::: warning

期末往年题答案正在整理中，别急。

:::

<div id="container">
  <div class="sidebar">
    <details v-for="i of problist">
      <summary>{{ i.title }}</summary>
      <ul>
        <li v-for="j of i.problems"
          class="prob-title"
          @click="() => loadSource(j)"
          :class="{ active: currentId === j.id }"
        >
          {{ j.title }}
        </li>
      </ul>
    </details>
  </div>
  <div class="content">
    <div v-if="currentId !== null" class="tabs-container">
      <div class="tabs">
        <div class="tab" @click="() => activeTab = 'cpp'" :class="{ active: activeTab === 'cpp' }">
          C++ 风格解答
        </div>
        <div class="tab" @click="() => activeTab = 'ica'" :class="{ active: activeTab === 'ica' }">
          计概 A 风格解答
        </div>
        <div class="tab" @click="() => activeTab = 'dsc'" :class="{ active: activeTab === 'dsc' }">
          题目详情
        </div>
      </div>
      <button class="expand-btn" @click="expand">&nbsp;全&nbsp;</button>
      <button class="close-btn" @click="shrink">&nbsp;x&nbsp;</button>
    </div>
    <pre
      v-if="currentId && sources[currentId] && activeTab !== 'dsc'"
    ><code
      v-html="sources[currentId][activeTab === 'cpp' ? 0 : 1]"
    ></code></pre>
    <div class="dsc" v-if="currentId && activeTab === 'dsc'" v-html="currentDsc">
    </div>
    <div class="dsc" v-if="currentId === null">
      请在左侧题目列表选择题目<br>
      <a href="javascript:void 0" @click="expand">
        全屏模式
      </a>
    </div>
  </div>
</div>

<style>
#container {
  display: flex;
  background-color: var(--vp-c-bg);
  flex-direction: row;
  height: calc(100vh - var(--vp-nav-height));
}
#container.fullscreen {
  z-index: 100; 
  width: 100vw;
  height: 100vh;
  padding-left: 1rem;
  position: fixed; 
  top: 0;
  left: 0;
}
#container .sidebar {
  flex-basis: 30%;
  flex-shrink: 0;
  overflow-y: scroll;
}
.prob-title {
  cursor: pointer;
  border-radius: 5px;
}
.prob-title:hover {
  background-color: var(--vp-c-text-4)
}
.prob-title.active {
  font-weight: bold;
}
#container .content {
  width: 70%;
  display: flex;
  flex-direction: column;
}
#container .content > pre {
  flex-grow: 1;
  margin: 0;
  padding: 1rem;
  line-height: var(--vp-code-line-height);
  font-size: var(--vp-code-font-size);
  color: var(--vp-code-block-color);
  background-color: var(--vp-code-block-bg);
  overflow: auto;
}
.tabs-container {
  display: flex;
  flex-direction: row;
}
.close-btn,.fullscreen .expand-btn {
  display: none;
}
.fullscreen .close-btn,.expand-btn {
  display: block;
}
.tabs {
  flex-grow: 1;
  display: flex;
  flex-wrap: wrap;
  align-items: flex-end;
  --color: 16 16 16;
}
.dark .tabs {
  --color: 240 240 240;
}
.tab {
  --text-opacity: 0.5;
  --border-opacity: 0.2;
  box-sizing: border-box;
  border-width: 0;
  position: relative;
  display: inline-flex;
  cursor: pointer;
  user-select: none;
  flex-wrap: wrap;
  align-items: center;
  justify-content: center;
  text-align: center;
  height: 2rem;
  font-size: .875rem;
  line-height: 1.25rem;
  line-height: 2;
  color: rgba(var(--color) / var(--text-opacity));
  border-color:  rgba(var(--color) / var(--border-opacity));
  padding-left: 1rem;
  padding-right: 1rem;
  border-style: solid;
  border-bottom-width: 2px;
}
.tab.active {
  --text-opacity: 1;
  --border-opacity: 1;
}
.tab:hover {
  text-decoration: none;
  --text-opacity: 1;
}
.dsc {
  padding: 1rem;
  overflow: auto;
}
</style>

<script setup>
import { ref } from "vue";
import Prism from "prismjs";
import "prismjs/components/prism-clike.js";
import "prismjs/components/prism-c.js";
import "prismjs/components/prism-cpp.js";
import "prismjs/themes/prism-dark.min.css";

const problist = ref([]);
const sources = ref({});
const currentId = ref(null);
const currentDsc = ref(null);
const activeTab = ref("ica");

async function loadSource(prob) {
  const id = prob.id;
  const html = `${prob.description}<h4>关于输入</h4>${prob.aboutInput}<h4>关于输出</h4>${prob.aboutOutput}`;
  currentId.value = id;
  currentDsc.value = html;
  if (!(id in sources.value)) {
    const source = await Promise.all([
      `/cpp/${id}.cpp`,
      `/ica/${id}.cpp`
    ].map(async (l) => {
      const r = await fetch(l);
      if (r.status === 404) {
        return "// 暂无解答";
      } else {
        return r.text();
      }
    }));
    sources.value[id] = source.map(s => Prism.highlight(s, Prism.languages.cpp, "cpp"));
  }
}

fetch("/problist.json").then(r => r.json()).then(v => problist.value = v);

function expand() {
  document.querySelector("#container").classList.add("fullscreen");
}
function shrink() {
  document.querySelector("#container").classList.remove("fullscreen");
}

</script>
