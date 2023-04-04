<template>
  <div class="body">
    <el-card class="header">
      <el-form :inline="true" :model="brand">
        <el-form-item label="作物名称">
          <el-input v-model="brand.equipmentName" aria-placeholder="设备名称" class="el-input_inner"></el-input>
        </el-form-item>
        <el-form-item>
          <el-button type="primary" @click="onSubmit" class="el-button">搜索</el-button >
          <el-button icon="el-icon-delete" type="primary" @click="clearButton" class="el-button"></el-button>
        </el-form-item>
      </el-form>  
    </el-card>
    <el-card>
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
    handleDelete(row){
      console.log(row)
    },
    handleApple(row){
      console.log(row)
    },
    //搜索按钮
    onSubmit(){
      console.log(this.brand);
    },
    //提交按钮
    addBrand(){
      console.log(this.formLabelAlign);
    },
    clearButton(){
      this.input1 = '';
      this.input2 = '';
    },
    getTableData(){
      this.$axios.get("http://8.130.45.241:8099/user/datacenter").then(res=>{
        this.tableData = res.data;
      })
    }
  },
  mounted() {
    this.intervalId = setInterval(() => {
      this.getTableData();
    }, 1000);
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
  width: 1480px;
}
.header {
  margin: auto;
  height:110px;
  width: 100%;
  .el-input_inner {
    width: 300px;
   padding: 5px 15px;
   float: left;
  }
}

.el-button {
  margin: 5px 14px 14px 40px;
  width: 100px;
  //padding-left: 20px;
  height: 40px;
  float: left;
}


</style>