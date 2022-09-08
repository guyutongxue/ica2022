# 将 GCC 编译信息翻译为中文

::: tip

仅支持 gcc/g++ 编译器（**不支持 MSVC 和 Clang**）。翻译词典生成自 GCC 12.1.0，不保证其它版本的翻译结果正确。

:::


<textarea class="input" placeholder="将英文粘贴在这里" v-model="input" @input="trigger"></textarea>


<textarea class="input" placeholder="翻译结果" readonly :value="translated"></textarea>

<style>
.input {
  width: 100%;
  height: 300px;
  border-radius: 8px;
  padding: 6px 10px;
  line-height: 1.2;
  border: 1px solid var(--vp-c-divider-light);
}
.input:focus {
  border: 1px solid var(--vp-c-brand-dark);
}
</style>

<script setup>
import { ref } from "vue";
import { replaceGccDiagnostics } from "@gytx/gcc-translation"

const input = ref("");
const translated = ref("");

async function trigger() {
  translated.value = await replaceGccDiagnostics(input.value, {
    color: false,
    version: "12.1.0"
  });
}
</script>
