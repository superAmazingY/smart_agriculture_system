<template>
  <div class="header-container">
    <div class="l-content">
      <div class="line"></div>
      <el-menu
          :default-active="activeIndex"
          class="el-menu-demo"
          mode="horizontal"
          @select="handleSelect"
          background-color=" #333"
          text-color="#fff"
          active-text-color="#ffd04b">
        <el-menu-item index="1" @click="pageButton">首页</el-menu-item>
        <el-submenu index="2">
          <template slot="title">功能中心</template>
          <el-menu-item index="2-1" @click="smartButton">智能监控</el-menu-item>
          <el-menu-item index="2-2" @click="dataButton">数据设置</el-menu-item>
          <el-menu-item index="2-3" @click="listButton">数据列表</el-menu-item>
          <el-menu-item index="2-4" @click="data2Button">设备设置</el-menu-item>
          <el-menu-item index="2-5" @click="list2Button">设备列表</el-menu-item>
        </el-submenu>
        <el-menu-item index="3" @click="personalButton">个人中心</el-menu-item>
      </el-menu>
    </div>
    <div class="r-content">
      <el-dropdown>
          <span class="el-dropdown-link">
            <img class="user" src="../assets/rice.jpg" alt="">
          </span>
          <el-dropdown-menu>
            <el-dropdown-item @click.native="exit">退出</el-dropdown-item>
          </el-dropdown-menu>
      </el-dropdown>
    </div>
  </div>

</template>

<script>
export default {
  data(){
    return{
      activeIndex: '1'
    };
  },
  methods:{
    exit(){
      this.$router.push({
        path:'/login'
      })
    },
    handleSelect(key, keyPath) {
      console.log(key, keyPath);
    },
    pageButton(){
      this.$router.push({
        path:'/home/main'
      })
    },
    smartButton(){
      this.$router.push({
        path:'/home/monitoring'
      })
    },
    dataButton(){
      this.$router.push({
        path:'/home/dataset'
      })
    },
    personalButton(){
      this.$router.push({
        path:'/home/personal'
      })
    },
    listButton(){
      this.$router.push({
        path:'/home/datalist'
      })
    },
    list2Button(){
      this.$router.push({
        path:'/home/facilitylist'
      })
    },
    data2Button(){
      this.$router.push({
        path:'/home/facilityset'
      })
    },
  }
}
</script>

<style lang="less" scoped>
.header-container{
  padding-left: 0;
  padding-right: 0;
  background: #333;
  height: 60px;
  display: flex;
  justify-content: space-between;
  align-items: center;
  .r-content{
    .user{
      width: 40px;
      height: 40px;
      border-radius: 50%;
    }
  }
}

</style>