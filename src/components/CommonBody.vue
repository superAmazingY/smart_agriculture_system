<template>
  <el-row>
    <el-col :span="8"><div class="grid-content bg-purple">
      <el-card class="box-card">
        <div class="user">
          <img src="../assets/logo.png" alt="">
          <div class="userinfo">
            <p class="name">Admin</p>
            <p class="access">超级管理员</p>
          </div>
        </div>
        <div class="login-info">
          <p>上次登录时间：<span>2023-1-28</span></p>
          <p>上次登录地点：<span>重庆</span></p>
        </div>
      </el-card>
      <el-card class="box-card" style="height: 345px">
        <p>异常数据分析</p>
      </el-card>
      </div></el-col>
    <el-col :span="16"><div class="grid-content bg-purple-light">
      <el-card class="box-card" style="height: 210px">
        <p>温度折线图</p>
      </el-card>
      <el-card class="box-card" style="height: 210px">
        <p>氮磷钾折线图</p>
      </el-card>
      <el-card class="box-card" style="height: 210px">
        <p>PH值折线图</p>
      </el-card>

    </div></el-col>
  </el-row>

</template>

<script>
export default {

}
</script>

<style lang="less" scoped>
.user {
  padding-bottom: 20px;
  margin-bottom: 20px;
  border-bottom: 1px solid #ccc;
  display: flex;
  align-items: center;
  img {
    margin-right: 40px;
    width: 150px;
    height: 150px;
    border-radius: 50%;
  }
  .userinfo {
    .name {
      font-size: 32px;
      margin-bottom: 10px;
    }
    .access {
      color: #999999;
    }
  }
}
.login-info {
  p {
    line-height: 28px;
    font-size: 14px;
    color: #999999;
    span {
      color: #666666;
      margin-left: 60px;
    }
  }
}

</style>