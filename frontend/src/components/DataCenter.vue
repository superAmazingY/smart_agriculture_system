<template>
  <div>
    <el-card class="header">
      <span>作物名称<el-input v-model="input1" class="el-input_inner"
                              placeholder="请输入内容"></el-input></span>
      <span>作物详情<el-input v-model="input2" class="el-input_inner"
                              placeholder="请输入内容"></el-input></span>
      <el-button class="el-button" icon="el-icon-search" type="primary">搜索</el-button>
      <el-button icon="el-icon-delete" type="primary" @click="clearButton"></el-button>
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
            <el-button type="text" @click="open">添加数据</el-button>
          </template>
          <template>
            <el-button size="mini" @click="handleEdit" type="primary">编辑</el-button>
            <el-button size="mini" @click="handleApple" type="success">应用</el-button>
            <el-button size="mini" type="danger" @click="handleDelete">删除</el-button>
          </template>
        </el-table-column>
      </el-table>
    </el-card>
  </div>
</template>

<script>
export default {
  data() {
    return {
      input1: '',
      input2: '',
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
    open() {
      this.$alert('<strong>这是片段</strong>', '添加数据', {
        dangerouslyUseHTMLString: true
      });
    },
    handleEdit(){

    },
    handleDelete(){

    },
    handleApple(){

    },
    clearButton(){
      this.input1 = '';
      this.input2 = '';
    }
  }
}
</script >

<style lang="less" scoped>
.header {
  margin: auto;
  width: 100%;
  span {
    float: left;
    width: 400px;
    margin: auto;
    padding: 15px;
  }
  .el-input_inner {
    width: 300px;
    padding: 0 15px;
  }
}

.el-button {
  margin: 14px;
  margin-left: 40px;
  width: 100px;
  padding-left: 20px;
  height: 40px;
}
</style>