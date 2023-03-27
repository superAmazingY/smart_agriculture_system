<template>
  <div class="body">
    <el-card class="header">
      <el-form :inline="true" :model="brand">
        <el-form-item label="作物名称">
          <el-input v-model="brand.equipmentName" aria-placeholder="设备名称" class="el-input_inner"></el-input>
        </el-form-item>
        <el-form-item label="作物详情">
          <el-input v-model="brand.equipmentView" aria-placeholder="设备概述" class="el-input_inner"></el-input>
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
        <el-table-column label="序号" prop="id"  width="100"></el-table-column>
        <el-table-column label="名称" prop="name" width="100"></el-table-column>
        <el-table-column label="PH范围" prop="PHvalue" width="100"></el-table-column>
        <el-table-column label="温度范围" prop="temperatureValue" width="100"></el-table-column>
        <el-table-column label="湿度范围" prop="humidityValue" width="100"></el-table-column>
        <el-table-column label="氮含量范围" prop="Nvalue" width="100"></el-table-column>
        <el-table-column label="磷含量范围" prop="Pvalue" width="100"></el-table-column>
        <el-table-column label="钾含量范围" prop="Kvalue" width="100"></el-table-column>
        <el-table-column label="添加日期" prop="date" width="150"></el-table-column>
        <el-table-column align="right">
          <template slot="header">
            <el-row>
              <el-button type="primary" plain @click="dialogVisible=true">添加数据</el-button>
            </el-row>
          </template>
          <template>
            <el-button size="mini" @click="handleEdit" type="primary">编辑</el-button>
            <el-button size="mini" @click="handleApple" type="success">应用</el-button>
            <el-button size="mini" type="danger" @click="handleDelete">删除</el-button>
          </template>
        </el-table-column>
      </el-table>
    </el-card>
    <el-dialog
        title="添加数据"
        :visible.sync="dialogVisible"
        width="40%"
    >
      <div class="el-dialog-div">
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
      </div >
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
        equipmentView:''
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
      multipleSelection:[],
      tableData: [{
        id: '1',
        date: '2023-03-19',
        name: '苹果',
        PHvalue: '7-10',
        temperatureValue: '25-28',
        humidityValue: '24-55',
        Nvalue: '22-24',
        Pvalue: '24-31',
        Kvalue: '27-35'
      }, {
        id: '2',
        date: '2023-03-19',
        name: '香蕉',
        PHvalue: '7-10',
        temperatureValue: '25-28',
        humidityValue: '24-55',
        Nvalue: '22-24',
        Pvalue: '24-31',
        Kvalue: '27-35'
      }, {
        id: '3',
        date: '2023-03-19',
        name: '菠萝',
        PHvalue: '7-10',
        temperatureValue: '25-28',
        humidityValue: '24-55',
        Nvalue: '22-24',
        Pvalue: '24-31',
        Kvalue: '27-35'
      }, {
        id: '4',
        date: '2016-05-03',
        name: '草莓',
        PHvalue: '7-10',
        temperatureValue: '25-28',
        humidityValue: '24-55',
        Nvalue: '22-24',
        Pvalue: '24-31',
        Kvalue: '27-35'
      },{
        id: '5',
        date: '2016-05-03',
        name: '小麦',
        PHvalue: '7-10',
        temperatureValue: '25-28',
        humidityValue: '24-55',
        Nvalue: '22-24',
        Pvalue: '24-31',
        Kvalue: '27-35'
      }],
      search: ''
    }
  },
  methods: {
    handleEdit(){

    },
    handleDelete(){

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
    }
  }
}
</script >

<style lang="less" scoped>
.body{
  margin:auto;
  text-align: center;
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

.el-dialog-div{
  height: 60vh;
  overflow: auto;
}

</style>