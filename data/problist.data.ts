import { defineLoader } from 'vitepress'
import fs from "fs"

export interface Data {
  // data type
}

declare const data: Data
export { data }

export default defineLoader({
  // type checked loader options
  watch: ['./problist.json'],
  load() {
    const data = JSON.parse(fs.readFileSync("./data/problist.json", 'utf-8'))
    return data
  }
})