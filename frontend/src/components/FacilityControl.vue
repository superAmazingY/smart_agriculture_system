<template>
  <div class="document">
    <el-row :gutter="20" >
      <!--第一列-->
      <el-col :span="8">
        <div class="container">
          <el-card class="box-card">
            <div slot="header" >
              <span>风扇设备控制</span>
            </div>
            <div class="text">
              <p>当前环境温度</p>
            </div>
            <el-switch
                v-model="value1"
                @change="toggleLed"
                active-color="#13ce66"
                inactive-color="#ff4949"
                active-text="打开"
                inactive-text="关闭">
            </el-switch>
          </el-card>
        </div>

        <div class="container">
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
        </div>
        <div class="container">
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
        </div>
      </el-col>

      <el-col :span="8">
        <!--第二列-->
        <div class="container">
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
        </div>

        <div class="container">
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
        </div>

        <div class="container">
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
        </div>
      </el-col>
     

      
      <el-col :span="8">
      <!--第三列-->
        <div class="container">
          <el-card class="box-card">
            <div slot="header" style="border: 0;">
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
        </div>

        <div class="container">
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
        </div>

        <div class="container">
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
        </div>
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
  methods: {
    toggleLed() {
      this.$axios.post('http://172.20.10.6:5000/api/led/toggle', {
        status: this.value1 ? 1 : 0
      }).then(response => {
        console.log(response.data);
      }).catch(error => {
        console.log(error);
      });
    }
  }
}
</script>

<style scoped lang="less">
.document{
  margin:auto;
  font-weight:1000;
  text-align: center;
  background: url(../assets/bg_image.jpg)  no-repeat;
  background-size:cover;
  width: 1490px;
}
.container{
  //background-color: rgba(95, 172, 235, 0.5);
  opacity:1.0;
  
}
.box-card {
  background-color: rgba(17, 91, 151, 0.5);
  width: 480px;
  border:0;
  margin-top: 20px;
  color:honeydew;
  
  .text {
    font-weight:900;
    font-size: 14px;
    margin-bottom: 18px;
    border: 1px solid black;
    border-radius: 25px;
    width:450px;
    height:40px;
    border-color: azure;
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
