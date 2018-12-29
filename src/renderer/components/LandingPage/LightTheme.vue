<template>
  <div class="theme" v-on:mouseover="selectLight">
    <sun-icon/>
    <div class="theme-btn">
        Light Theme
    </div>
  </div>
</template>

<script>
  import SunIcon from './SunIcon'

  export default {
    name: 'light-theme',
    components: {
      SunIcon
    },
    methods: {
      selectLight () {
        this.$store.commit('layout/selectLight')
      }
    }
  }
</script>

<style scoped>
.theme {
    height: fit-content;
    cursor: pointer;
}
.theme-btn {
    cursor: pointer;
    font-size: 20px;
    text-transform: uppercase;
    border: 2px solid;
    text-align: center;
    padding: 10px 20px;
    margin-top: 30px;
    color: #2c3e50;
    transition: background-color .5s ease-in-out 0s;
}
.active .theme-btn {
    background-color: rgba(44, 62, 80, 0.08);
}
</style>
