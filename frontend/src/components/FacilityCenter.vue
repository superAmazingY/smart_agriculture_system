<template>
  <div class="body">
    <div class="container">
      <el-card class="header">
        <el-form :inline="true" :model="brand">
          <el-form-item label="" >
            <el-input v-model="brand.equipmentName" placeholder="设备名称"   class="el-input_inner"></el-input>
          </el-form-item>
          <el-form-item>
            <el-button type="primary" @click="onSubmit" class="el-button">搜索</el-button >
            <el-button icon="el-icon-delete" type="primary" @click="clearButton" class="el-button"></el-button>
          </el-form-item>
        </el-form>
      </el-card>
    </div>
    <div class="container">
      <el-card>
        <el-table :data="tableData.filter(data => !search || data.name.toLowerCase().includes(search.toLowerCase()))"
                  height="470" style="width: 100%" >
          <el-table-column label="序号" prop="id"  width="100">
            <template slot-scope="scope">
              {{scope.$index+1}}
            </template>
          </el-table-column>
          <el-table-column label="设备名称" prop="name" width="150"></el-table-column>
          <el-table-column label="设备概述" prop="info" width="600"></el-table-column>
          <el-table-column label="数量" prop="number" width="100"></el-table-column>
          <el-table-column label="添加时间" prop="time" width="150"></el-table-column>
          <el-table-column align="right">
            <template slot="header">
              <el-row>
                <el-button type="text"  @click="dialogVisible=true">添加设备</el-button>
              </el-row>
            </template>
            <template slot-scope="scope">
              <el-button type="primary" size="small" @click.native.prevent="handleEdit(scope.row)">编辑</el-button>
              <el-button type="danger" size="small" @click.native.prevent="handleDelete(scope.row)">删除</el-button>
            </template>
          </el-table-column>
        </el-table>
      </el-card>
    </div>
    //编辑弹窗
  
    //添加数据弹窗
    <el-dialog
        title="添加设备"
        :visible.sync="dialogVisible"
        width="40%"
    >
      <el-form :label-position="labelPosition" label-width="80px" :model="formLabelAlign">
        <el-form-item label="设备名称">
          <el-input v-model="formLabelAlign.name"></el-input>
        </el-form-item>
        <el-form-item label="设备概述">
          <el-input v-model="formLabelAlign.info"></el-input>
        </el-form-item>
        <el-form-item label="数量">
          <el-input v-model="formLabelAlign.number"></el-input>
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

      //弹窗的表单内容
      labelPosition: 'right',
      formLabelAlign: {
        name: '',
        info: '',
        number: '',
      },
      //搜索
      brand:{
        equipmentName:'',
      },
      tableData: [],
      search: ''
    }
  },
  methods: {
    //添加设备
    addBrand(){
      const name=this.formLabelAlign.name;
      const info=this.formLabelAlign.info;
      const number=this.formLabelAlign.number;
      const date=this.getNowDate();
      if(!name){
        return this.$message({
          type:"error",
          message:"设备名称不能为空！",
        });
      }
      if(!number){
        return this.$message({
          type:"error",
          message:"设备数量不能为空！",
        });
      }
      if(!info){
        return this.$message({
          type:"error",
          message:"设备数量不能为空！",
        });
      }
        this.$axios.post(`http://8.130.45.241:8099/user/getFacilityData?name=${name}&info=${info}&number=${number}&date=${date}`, {
        }).then(res=>{
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
            }
        )
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
      this.$axios.post(`http://8.130.45.241:8099/user/deleteFacilityData?name=${row.name}`,{})
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
    },
    handleEdit(row){
      console.log(row);
      this.$axios.post(`http://8.130.45.241:8099/user/editeFacilityData?olname=${row.name}&newname={row.name}`)
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
      this.$axios.get("http://8.130.45.241:8099/user/facility").then(res=>{
        this.tableData = res.data;
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

  margin:auto;
  text-align: center;
  width: 1495px;
  background: url("../assets/bg_image.jpg");
  background-repeat: no-repeat;
  background-size: cover;
}
.header {
  margin: auto;
  height:110px;
  width: 100%;
  color:azure;
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
  height:0px;

}
.el-button {
  margin: 5px 14px 14px 40px;
  width: 100px;
  //padding-left: 20px;
  height: 40px;
  float: left;
}


</style>