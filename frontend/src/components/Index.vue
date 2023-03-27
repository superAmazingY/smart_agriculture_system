<template>
  <div class="body">
    <el-header class="header" >
      <img src="../assets/logo.png" width="50px" height="50px">
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
    <div>
      <div class="document-right">
        <el-row>
          <el-col :span="12">
            <el-card class="grid-content bg-purple">
              <div class="el-col-right">
                <el-breadcrumb separator="/ " classs="el-breadcrumb">
                  <el-breadcrumb-item >总设备</el-breadcrumb-item>
                  <el-breadcrumb-item > </el-breadcrumb-item>
                </el-breadcrumb>
              </div><br/><br/>
              <div class="el-col-right-document">
                <el-col :span="6">
                  <div>
                    <el-statistic title="" >
                      <template slot="formatter"> <span>10</span></template>
                    </el-statistic>
                  </div>
                </el-col>
              </div>
            </el-card>
          </el-col>

          <el-col :span="12">
            <el-card class="grid-content bg-purple">
              <div class="el-col-right">
                <el-breadcrumb separator="/ " classs="el-breadcrumb">
                  <el-breadcrumb-item >在线设备</el-breadcrumb-item>
                  <el-breadcrumb-item > </el-breadcrumb-item>
                </el-breadcrumb>
              </div><br/><br/>
              <div class="el-col-right-document">
                <el-col :span="6">
                  <div>
                    <el-statistic title="" >
                      <template slot="formatter"> <span>3</span></template>
                    </el-statistic>
                  </div>
                </el-col>
              </div>
            </el-card>
          </el-col>
        </el-row><hr>

        <el-row>
          <el-col :span="12">
            <el-card class="grid-content bg-purple-light">
              <div class="el-col-right">
                <el-breadcrumb separator="/ " classs="el-breadcrumb">
                  <el-breadcrumb-item >总传感器</el-breadcrumb-item>
                  <el-breadcrumb-item > </el-breadcrumb-item>
                </el-breadcrumb>
              </div><br/><br/>
              <div class="el-col-right-document">
                <el-col :span="6">
                  <div>
                    <el-statistic title="" >
                      <template slot="formatter" ><span text="center">45</span> </template>
                    </el-statistic>
                  </div>
                </el-col>
              </div>
            </el-card>
          </el-col>

          <el-col :span="12">
            <el-card class="grid-content bg-purple-light">
              <div class="el-col-right">
                <el-breadcrumb separator="/ " classs="el-breadcrumb">
                  <el-breadcrumb-item >在线传感器</el-breadcrumb-item>
                  <el-breadcrumb-item > </el-breadcrumb-item>
                </el-breadcrumb>
              </div><br/><br/>
              <div class="el-col-right-document">
                <el-col :span="6">
                  <div>
                    <el-statistic title="" >
                      <template slot="formatter" ><span text="center">42 </span> </template>
                    </el-statistic>
                  </div>
                </el-col>
              </div>
            </el-card>
          </el-col>
        </el-row><hr>
      </div>
    </div>
  </div>
</template>

<script>
export default {
  created(){
    window.WIDGET = {
      "CONFIG": {
        "layout": "2",
        "width": 300,
        "height": 450,
        "background": "2",
        "dataColor": "000000",
        "key": "49c92f65b0a84c3c98356dd3d1705736"
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
  img{
    float:left;
    padding:10px 20px;
  }
  h3{
    float:left;
    padding:0px 20px;
    text-align: center;
    display: inline;
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

