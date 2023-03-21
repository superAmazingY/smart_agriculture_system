<template>
  <div class="header-container">
    <div class="l-content">
      <div class="line"></div>
      <el-menu
          :default-active="activeIndex"
          class="el-menu-demo"
          mode="horizontal"
          background-color=" #333"
          text-color="#fff"
          active-text-color="#ffd04b">
        <el-menu-item index="1" @click="mainButton">首页</el-menu-item>
        <el-submenu index="2">
          <template slot="title">功能中心</template>
          <el-menu-item index="2-1" @click="monitoringButton">智能监控</el-menu-item>
          <el-menu-item index="2-2" @click="datacenter">数据中心</el-menu-item>
          <el-menu-item index="2-3" @click="facilityCenterButton">设备中心</el-menu-item>
        </el-submenu>
        <el-menu-item index="3" @click="facilityControlButton">设备控制</el-menu-item>
      </el-menu>
    </div>
    <div class="r-content">
      <el-dropdown>
          <span class="el-dropdown-link">
            <img class="user" src="../assets/rice.jpg" alt="">
          </span>
          <el-dropdown-menu>
            <el-dropdown-item @click.native="exitButton">退出</el-dropdown-item>
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
    exitButton(){
      this.$router.push({
        path:'/login'
      })
    },
    monitoringButton(){
      this.$router.push({
        path:'/home/monitoring'
      })
    },
    facilityCenterButton(){
      this.$router.push({
        path:'/home/facilityCenter'
      })
    },
    datacenter(){
      this.$router.push({
        path:'/home/datacenter'
      })
    },
    facilityControlButton(){
      this.$router.push({
        path:'/home/facilityControl'
      })
    },
    mainButton(){
      this.$router.push({
        path:'/home/main'
      })
    }

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