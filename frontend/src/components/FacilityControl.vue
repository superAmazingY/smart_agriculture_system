<template>
  <el-row :gutter="20">
    <!--第一列-->
    <el-col :span="8">
      <div class="grid-content bg-purple">
        <el-card class="box-card">
          <div slot="header" >
            <span>风扇设备控制</span>
          </div>
          <div class="text">

          </div>
        </el-card>
      </div>

      <el-card class="box-card">
        <div slot="header" >
          <span>氮磷钾传感器控制</span>
        </div>
        <div class="text">

        </div>
      </el-card>
    </el-col>

    <el-col :span="8">
      <!--第二列-->
      <div class="grid-content bg-purple">
      <el-card class="box-card">
        <div slot="header" >
          <span>水泵设备控制</span>
        </div>
        <div class="text">

        </div>
      </el-card>
      </div>
    </el-col>

    <el-col :span="8">
      <!--第三列-->
      <div class="grid-content bg-purple">
      <el-card class="box-card">
        <div slot="header" >
          <span>PH传感器控制</span>
        </div>
        <div class="text">

        </div>
      </el-card>
      </div>
    </el-col>

  </el-row>
</template>

<script>
export default {
  data(){
    return{

    }
  }
}
</script>

<style scoped lang="less">
  .box-card {
    width: 480px;
    margin-top: 20px;
    .text {
      font-size: 14px;
      margin-bottom: 18px;
    }
    span{
      font-size: 18px;
    }
  }
</style>