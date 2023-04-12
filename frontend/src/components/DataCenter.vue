<template>
  <div class="body">
    <div class="container">
      <el-card class="header">
        <el-form :inline="true" :model="brand">
          <el-form-item label="">
            <el-input v-model="brand.equipmentName" placeholder="设备名称" class="el-input_inner"></el-input>
          </el-form-item>
          <el-form-item>
            <el-button type="primary" @click="onSubmit" class="el-button">搜索</el-button >
            <el-button icon="el-icon-delete" type="primary" @click="clearButton" class="el-button"></el-button>
          </el-form-item>
        </el-form>  
      </el-card>
    </div>
    <div class="container">
      <el-card class="el-card">
        <el-table :data="tableData.filter(data => !search || data.name.toLowerCase().includes(search.toLowerCase()))"
                  height="480" style="width: 100%">
          <el-table-column label="序号" prop="id"  width="100">
            <template slot-scope="scope">
              {{scope.$index+1}}
            </template>
          </el-table-column>
          <el-table-column label="名称" prop="name" width="100"></el-table-column>
          <el-table-column label="PH范围" prop="ph_value" width="100"></el-table-column>
          <el-table-column label="温度范围" prop="temperature_value" width="100"></el-table-column>
          <el-table-column label="湿度范围" prop="humidity_value" width="100"></el-table-column>
          <el-table-column label="氮含量范围" prop="n_value" width="100"></el-table-column>
          <el-table-column label="磷含量范围" prop="p_value" width="100"></el-table-column>
          <el-table-column label="钾含量范围" prop="k_value" width="100"></el-table-column>
          <el-table-column label="添加日期" prop="time" width="150"></el-table-column>
          <el-table-column align="right">
            <template slot="header">
              <el-row>
                <el-button type="text"  @click="dialogVisible=true">添加数据</el-button>
              </el-row>
            </template>
            <template slot-scope="scope">
              <el-button type="primary" size="small" @click.native.prevent="handleEdit(scope.row)">编辑</el-button>
              <el-button type="success" size="small" @click.native.prevent="handleApple(scope.row)">应用</el-button>
              <el-button type="danger" size="small" @click.native.prevent="handleDelete(scope.row)">删除</el-button>
            </template>
          </el-table-column>
        </el-table>
      </el-card>
    </div>
    <el-dialog
        title="添加数据"
        :visible.sync="dialogVisible"
        width="40%"
    >
        <el-form :label-position="labelPosition" label-width="100px" :model="formLabelAlign">
          <el-form-item label="名称">
            <el-input v-model="formLabelAlign.name"></el-input>
          </el-form-item>
          <el-form-item label="PH范围">
            <el-input v-model="formLabelAlign.PHvalue"></el-input>
          </el-form-item>
          <el-form-item label="温度范围">
            <el-input v-model="formLabelAlign.temperatureValue"></el-input>
          </el-form-item>
          <el-form-item label="湿度范围">
            <el-input v-model="formLabelAlign.humidityValue"></el-input>
          </el-form-item>
          <el-form-item label="氮含量范围">
            <el-input v-model="formLabelAlign.Nvalue"></el-input>
          </el-form-item>
          <el-form-item label="磷含量范围">
            <el-input v-model="formLabelAlign.Pvalue"></el-input>
          </el-form-item>
          <el-form-item label="钾含量范围">
            <el-input v-model="formLabelAlign.Kvalue"></el-input>
          </el-form-item>
          <el-form-item>
            <el-button type="primary" @click="addBrand">立即创建</el-button>
            <el-button @click="dialogVisible=false">取消</el-button>
          </el-form-item>
        </el-form>
    </el-dialog>
  </div>
</template>

<script>
export default {
  data() {
    return {
      input1: '',
      input2: '',
      dialogVisible: false,
      //搜索
      brand:{
        equipmentName:'',
      },
       //弹窗的表单内容
       labelPosition: 'right',
       formLabelAlign: {
        name: '',
        PHvalue: '',
        temperatureValue: '',
        humidityValue: '',
        Nvalue: '',
        Pvalue: '',
        Kvalue: ''
      },
      tableData: [],
      search: ''
    }
  },
  methods: {
    handleEdit(row){
      console.log(row);
    },
    handleApple(row){
      console.log(row)
    },
    //搜索按钮
    onSubmit(){
      console.log(this.brand);
    },
    clearButton(){
      this.input1 = '';
      this.input2 = '';
    },
    getTableData(){
      this.$axios.get("http://8.130.45.241:8099/user/datacenter").then(res=>{
        this.tableData = res.data;
      })
    },
    //添加设备
    addBrand(){
      const name=this.formLabelAlign.name;
      const PHvalue=this.formLabelAlign.PHvalue;
      const Nvalue=this.formLabelAlign.Nvalue;
      const Pvalue=this.formLabelAlign.Pvalue;
      const Kvalue=this.formLabelAlign.Kvalue;
      const temperatureValue=this.formLabelAlign.temperatureValue;
      const humidityValue=this.formLabelAlign.humidityValue;
      const date=this.getNowDate();
      if(!name){
        return this.$message({
          type:"error",
          message:"名称不能为空！",
        });
      }
      if(!PHvalue){
        return this.$message({
          type:"error",
          message:"PH值范围不能为空！",
        });
      }
      if(!Nvalue){
        return this.$message({
          type:"error",
          message:"氮含量范围不能为空！",
        });
      }
      if(!Pvalue){
        return this.$message({
          type:"error",
          message:"磷含量范围不能为空！",
        });
      }
      if(!Kvalue){
        return this.$message({
          type:"error",
          message:"钾含量范围不能为空！",
        });
      }
      if(!temperatureValue){
        return this.$message({
          type:"error",
          message:"温度范围不能为空！",
        });
      }
      if(!humidityValue){
        return this.$message({
          type:"error",
          message:"湿度范围不能为空！",
        });
      }
      this.$axios.post(`http://8.130.45.241:8099/user/getCenterData?name=${name}&ph=${PHvalue}&temperature=${temperatureValue}&humidity=${humidityValue}&N=${Nvalue}&P=${Pvalue}&K=${Kvalue}&date=${date}`,
      {}).then(res=>{
        if(res.data.data === "添加成功"){
                return this.$message({
                  type:"success",
                  message:"添加成功",
                })
              }
        else{
          return this.$message({
            type:"error",
            message:"添加失败",
          })
        }
      })
      this.dialogVisible = false;
    },
    //获取当前系统时间
    getNowDate(){
      const timeOne = new Date()
      const year = timeOne.getFullYear()
      let month = timeOne.getMonth() + 1
      let day = timeOne.getDate()
      month = month < 10 ? '0' + month : month
      day = day < 10 ? '0' + day : day
      return `${year}-${month}-${day}`
    },
    //删除设备
    handleDelete(row){
      console.log(row.name);
      //const name=this.formLabelAlign.row.name;
      this.$axios.post(`http://8.130.45.241:8099/user/deleteCenterData?name=${row.name}`,{})
      .then(res=>{
        if(res.data.data ==="删除成功"){
          return this.$message({
            type:"success",
            message:"删除成功",
          })
        }else{
          return this.$message({
            type:"error",
            message:"删除异常",
          })
        }
      })
    }
  },
  mounted() {
    this.intervalId = setInterval(() => {
      this.getTableData();
    }, 500);
  },
  beforeDestroy() {
    clearInterval(this.intervalId);
  },
}
</script >

<style lang="less" scoped>
.body{
  color:aliceblue;
  margin:auto;
  text-align: center;
  width: 1490px;
  background: url("../assets/bg_image.jpg");
  background-repeat: no-repeat;
  background-size: cover;
  //margin-top: -20px;
}
.header {
  margin: auto;
  height:110px;
  width: 100%;
  background-color: rgba(17, 91, 151, 0.5);
  .el-input_inner {
    width: 300px;
   padding: 5px 15px;
   float: left;
  }
}
.container{
  //background-color: rgba(95, 172, 235, 0.5);
  opacity:0.8;
  .el-card{
    background-color: rgba(17, 91, 151, 0.5);
    border:0;
    
  }
}
/deep/.el-table,/deep/.el-table__expanded-cell{
  background-color:  transparent !important;
 
  /deep/.el-table th,
  /deep/.el-table tr,
  /deep/.el-table td{
  background-color: transparent !important;
  }
}
.el-table::before{
  left:0;
  bottom: 0;
  width:100%;
  height:0;

}

.el-button {
  margin: 5px 14px 14px 40px;
  width: 100px;
  //padding-left: 20px;
  height: 40px;
  float: left;
}


 
 
</style>