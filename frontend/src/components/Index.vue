<template>
  <div class="body">
    <el-header class="header" >
      <div class="r-content">
        <span class="el-dropdown-link">
            <img class="user" src="../assets/rice.jpg" alt="">
          </span>
        <!-- <el-col :span="12">
          <div class="demo-basic--circle">
            <div class="block"><el-avatar :size="50" :src="circleUrl"></el-avatar></div>
            <div class="block" v-for="size in sizeList" :key="size">
              <el-avatar :size="size" :src="circleUrl"></el-avatar>
            </div>
          </div>
        </el-col> -->
      </div>
      <!-- <img src="../assets/logo.png" width="50px" height="50px"> -->
      <h3>欢迎来到智慧农业检测系统</h3>
    </el-header>
    <div class="clear"></div>
    <!--天气预报-->
    <el-card class="wheather">
      <h4>天气信息</h4>
      <i class="el-icon-sunny"></i>
      <div id="he-plugin-standard"></div>
    </el-card>
    <!--分布-->

    <div class="pic">
      <img src="../assets/cotton.jpg"/>
      <img src="../assets/sesame.jpg"/>
      <img src="../assets/potato.jpg"/>
      <img src="../assets/barley.jpg"/>
    </div>
    <div class="block">
      <el-timeline>
        <el-timeline-item timestamp="春季(3——5月)" placement="top">
          <el-card class="card">
            <h4>花生，棉花，大豆，水稻等，冬前育苗、早春移栽的作物包括番茄、彩色辣椒</h4>
          </el-card>
        </el-timeline-item>
        <el-timeline-item timestamp="夏季(6——8月)" placement="top">
          <el-card class="card">
            <h4>早稻，早中稻，芝麻，花生等</h4>
          </el-card>
        </el-timeline-item>
        <el-timeline-item timestamp="秋季(9——11月)" placement="top">
          <el-card class="card">
            <h4>小麦，油菜，土豆，甜菜等</h4>
          </el-card>
        </el-timeline-item>
        <el-timeline-item timestamp="冬季(12——2月)" placement="top">
          <el-card class="card">
            <h4>大麦，蚕豆，豌豆，油菜等</h4>
          </el-card>
        </el-timeline-item>
      </el-timeline>
    </div>
  </div>
</template>

<script>
export default {
  data(){
    return{

    }
  },
  created(){
    window.WIDGET = {
      "CONFIG": {
        "layout": "2",
        "width": 300,
        "height": 450,
        "background": "2",
        "dataColor": "000000",
        "key": "83134152765846c9b98243bdf23fa6f1"
      }

    };
    (function (d) {
      var c = d.createElement('link')
      c.rel = 'stylesheet'
      c.href = 'https://widget.qweather.net/standard/static/css/he-standard.css?v=2.0'
      var s = d.createElement('script')
      s.src = 'https://widget.qweather.net/standard/static/js/he-standard-common.js?v=2.0"'
      var sn = d.getElementsByTagName('script')[0]
      sn.parentNode.insertBefore(c, sn)
      sn.parentNode.insertBefore(s, sn)
      s.onload=()=>{
        //自动宽度
        setTimeout(() => {
          document.getElementById("he-plugin-standard").style.width  = "100%";
        }, 100);
      }
    })(document)

  }
};
</script>

<style scoped lang="less">
.body{
  margin:auto;
  text-align: center;
}
.header{
  border-radius: 2px;
  border:1px  grey;
  width:100%;
  height:100px;
  box-shadow: 0 2px 2px 0 rgba(0, .22, .22, .22);
  text-align: center;
  padding:0px 20px;
  margin-left:5px;
  margin-bottom: 20px;
  float:left;
  .r-content{
    float:left;
    padding:7px 20px;
    .user{
      width: 45px;
      height: 45px;
      border-radius: 50%;
    }
  }
  h3{
    float:left;
    padding:15px 20px;
    text-align: center;
    display: inline;
  }
}
.pic{
  width:15%;
  float: left;
  height:535px;
  margin-left: 25px;
  img{
    width:100%;
    height:25%;
  }
}
.block{
  width:55%;
  padding-right: 0px;
  float: right;
  .card{
    height: 94px;
  }
}
.clear{
  clear: both;
}
.wheather{
  float:left;
  border-radius: 2px;
  margin: auto auto auto 5px;
  border:2px  grey;
  width:25%;
  height:550px;
  padding:0px 20px;
  box-shadow: 0 2px 2px 0 rgba(0, 0, 0, .22);
  h4{
    float:left;
    width:25%;
    height:10px;
  }
  i{
    height:10px;
    padding-top:25px;
    float:left;
  }
}
.document-right{
  width:69%;
  height:520px;
  margin:auto;
  padding:20px;
  float:right;
}
.el-breadcrumb{
    height:30px;
    margin-top:10px;
}
.el-col10{
  width:100px;
  height:70px;
  border:1px solid grey;
  background-color:whitesmoke;
  text-align: center;
  border-radius: 4px;
  padding-top:10px;
  margin:0 10px;
  span{
    color:green;
  }
}
.el-col-right-document{
    width:100px;
    height:80px;
  margin: auto auto auto 10px;
  padding:10px 5px;
    span{
      text-align: center;
      width:50px;
      color:green;
      padding:20px 200px ;
    }
  }
.el-row {
    margin-bottom: 20px;
    &:last-child {
      margin-bottom: 0;
    }
  }
  .el-col {
    border-radius: 0px;
  }

  .bg-purple {
    width:300px;
    height:150px;
    margin:10px ;
    text-align: center;
  }
  .bg-purple-light {
    width:300px;
    height:150px;
    margin:10px ;
  }
</style>

