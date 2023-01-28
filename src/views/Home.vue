<template>
  <div>
    <el-container>
      <el-header>
        <common-header></common-header>
      </el-header>
      <el-main>
        <common-body></common-body>
      </el-main>
    </el-container>
  </div>

</template>

<script>
import commonHeader from "@/components/CommonHeader.vue";
import commonBody from "@/components/CommonBody.vue";

export default {
  components: {
    commonHeader,
    commonBody
  }

}
</script>

<style>

</style>