<template>
  <div class="theme" v-on:mouseover="selectDark">
    <moon-icon/>
    <div class="theme-btn">
        Dark Theme
    </div>
  </div>
</template>

<script>
  import MoonIcon from './MoonIcon'

  export default {
    name: 'dark-theme',
    components: {
      MoonIcon
    },
    methods: {
      selectDark () {
        this.$store.commit('layout/selectDark')
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
