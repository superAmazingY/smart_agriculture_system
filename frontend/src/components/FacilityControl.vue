<template>
  <div class="document">
    <el-row :gutter="20" >
      <!--第一列-->
      <el-col :span="8">
        <el-card class="box-card">
            <div slot="header" >
              <span>风扇设备控制</span>
            </div>
            <div class="text">
              <p>当前环境温度</p>
            </div>
            <el-switch
                v-model="value1"
                active-color="#13ce66"
                inactive-color="#ff4949"
                active-text="打开"
                inactive-text="关闭">
            </el-switch>
        </el-card>

        <el-card class="box-card">
          <div slot="header" >
            <span>氮设备控制</span>
          </div>
          <div class="text">
            <p>当前氮含量</p>
          </div>
          <el-switch
              v-model="value2"
              active-color="#13ce66"
              inactive-color="#ff4949"
              active-text="打开"
              inactive-text="关闭">
          </el-switch>
        </el-card>

        <el-card class="box-card">
          <div slot="header" >
            <span>PH传感器传感器控制</span>
          </div>
          <div class="text">
            <p>运行正常</p>
          </div>
          <el-switch
              v-model="value3"
              active-color="#13ce66"
              inactive-color="#ff4949"
              active-text="打开"
              inactive-text="关闭">
          </el-switch>
        </el-card>
      </el-col>

      <el-col :span="8">
        <!--第二列-->
        
        <el-card class="box-card">
          <div slot="header" >
            <span>水泵设备控制</span>
          </div>
          <div class="text">
            <p>当前湿度</p>
          </div>
          <el-switch
              v-model="value4"
              active-color="#13ce66"
              inactive-color="#ff4949"
              active-text="打开"
              inactive-text="关闭">
          </el-switch>
        </el-card>

        <el-card class="box-card">
          <div slot="header" >
            <span>磷设备控制</span>
          </div>
          <div class="text">
            <p>当前磷含量</p>
          </div>
          <el-switch
              v-model="value5"
              active-color="#13ce66"
              inactive-color="#ff4949"
              active-text="打开"
              inactive-text="关闭">
          </el-switch>
        </el-card>

        <el-card class="box-card">
          <div slot="header" >
            <span>温湿度传感器控制</span>
          </div>
          <div class="text">
            <p>运行正常</p>
          </div>
          <el-switch
              v-model="value6"
              active-color="#13ce66"
              inactive-color="#ff4949"
              active-text="打开"
              inactive-text="关闭">
          </el-switch>
        </el-card>
      </el-col>

      <el-col :span="8">
        <!--第三列-->
        <el-card class="box-card">
          <div slot="header" >
            <span>PH设备控制</span>
          </div>
          <div class="text">
            <p>当前PH值</p>
          </div>
          <el-switch
              v-model="value7"
              active-color="#13ce66"
              inactive-color="#ff4949"
              active-text="打开"
              inactive-text="关闭">
          </el-switch>
        </el-card>

        <el-card class="box-card">
          <div slot="header" >
            <span>钾设备控制</span>
          </div>
          <div class="text">
            <p>当前钾含量</p>
          </div>
          <el-switch
              v-model="value8"
              active-color="#13ce66"
              inactive-color="#ff4949"
              active-text="打开"
              inactive-text="关闭">
          </el-switch>
        </el-card>

        <el-card class="box-card">
          <div slot="header" >
            <span>氮磷钾传感器控制</span>
          </div>
          <div class="text">
            <p>运行正常</p>
          </div>
          <el-switch
              v-model="value9"
              active-color="#13ce66"
              inactive-color="#ff4949"
              active-text="打开"
              inactive-text="关闭">
          </el-switch>
        </el-card>
      </el-col>
    </el-row>
</div>
</template>

<script>
export default {
  data(){
    return{
      value1:false,
      value2:false,
      value3:true,
      value4:false,
      value5:false,
      value6:true,
      value7:false,
      value8:false,
      value9:true,
    }
  },
  methods(){

  },
}
</script>

<style scoped lang="less">
  .document{
    margin:auto;
    width:1525px;
    text-align: center;
  }
  .box-card {
    width: 480px;
    margin-top: 20px;
    .text {
      font-size: 14px;
      margin-bottom: 18px;
      border: 1px solid black;
      border-radius: 25px;
      width:450px;
      height:40px;
      p{
        text-align: center;
        padding-top: 10px;
      }
    }
    span{
      font-size: 18px;
    }
  }
</style>