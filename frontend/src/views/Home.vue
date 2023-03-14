<template>
  <div>
    <el-container>
      <el-header>
        <common-header></common-header>
      </el-header>
      <el-main>
        <router-view></router-view>
      </el-main>
    </el-container>
  </div>

</template>

<script>
import commonHeader from "@/components/CommonHeader.vue";

export default {
  components: {
    commonHeader,
  }

}
</script>

<style>

</style>