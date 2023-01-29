<template>
  <div class="header-container">
    <div class="l-content">
    </div>
    <div class="r-content">
      <el-dropdown>
          <span class="el-dropdown-link">
            <img class="user" src="../assets/rice.jpg">
          </span>
          <el-dropdown-menu slot="dropdown">
            <el-dropdown-item>设置</el-dropdown-item>
            <el-dropdown-item>退出</el-dropdown-item>
          </el-dropdown-menu>
      </el-dropdown>
    </div>
  </div>

</template>

<script>
export default {
  data(){
    return{

    };
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