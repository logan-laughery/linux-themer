<template>
  <div id="wrapper">
    <div class="center">
      <div class="title">
        Welcome
      </div>
      <div class="title">
        Select your preferred theme
      </div>
      <div class="subtitle">
        (Use mouse or arrow keys)
      </div>
    </div>
    <div class="options">
      <div class="left"
        :class="{ active: $store.getters['layout/isDarkSelected'] }"
        v-on:click="updateTheme('DARK')"
      >
        <dark-theme/>
      </div>
      <div class="right"
        :class="{ active: $store.getters['layout/isLightSelected'] }"
         v-on:click="updateTheme('LIGHT')"
      >
        <light-theme/>
      </div>
    </div>
  </div>
</template>

<script>
  import SystemInformation from './LandingPage/SystemInformation'
  import DarkTheme from './LandingPage/DarkTheme'
  import LightTheme from './LandingPage/LightTheme'

  export default {
    name: 'landing-page',
    components: {
      SystemInformation,
      DarkTheme,
      LightTheme
    },
    mounted () {
      window.addEventListener('keydown', this.handleKeypress)
    },
    methods: {
      open (link) {
        require('electron').shell.openExternal(link)
      },
      handleKeypress (event) {
        if (event.key === 'ArrowLeft') {
          console.log('left press')
          this.$store.commit('layout/selectDark')
        } else if (event.key === 'ArrowRight') {
          console.log('right press')
          this.$store.commit('layout/selectLight')
        } else if (event.key === 'Enter') {
          console.log('enter press')
          this.updateTheme()
        }
      },
      updateTheme (clickSelection) {
        const selection = clickSelection || this.$store.state.layout.selection

        if (selection === 'DARK') {
          require('electron').ipcRenderer.send('selection', 2)
        }
        if (selection === 'LIGHT') {
          require('electron').ipcRenderer.send('selection', 1)
        }
      }
    },
    beforeDestroy () {
      window.removeEventListener('keydown', this.handleKeypress)
    }
  }
</script>

<style>
  @import url('https://fonts.googleapis.com/css?family=Source+Sans+Pro');

  html {
    overflow: hidden;
  }

  * {
    box-sizing: border-box;
    margin: 0;
    padding: 0;
  }

  body { font-family: 'Source Sans Pro', sans-serif; }

  #wrapper {
    background-color: #f7f7f7;
    height: 100vh;
    width: 100vw;
    display: flex;
    flex-direction: column;
  }

  .center {
    display: flex;
    justify-content: center;
    align-content: center;
    flex-direction: column;
    padding-top: 60px;
  }

  .options {
    display: flex;
    flex-grow: 1;
  }

  .subtitle {
    color: #888;
    font-size: 25px;
    font-weight: initial;
    letter-spacing: .25px;
    margin-top: 10px;
    text-align: center;
  }

  .left {
    display: flex;
    flex-basis: 50%;
    justify-content: center;
    align-content: center;
    align-items: center;
  }
  
  .right {
    display: flex;
    flex-basis: 50%;
    justify-content: center;
    align-content: center;
    align-items: center;
  }

  .title {
    color: #2c3e50;
    font-size: 30px;
    font-weight: bold;
    margin-bottom: 6px;
    text-align: center;
  }

  .animated {
    -webkit-animation-duration: .5s;
    animation-duration: .5s;
    -webkit-animation-fill-mode: both;
    animation-fill-mode: both;
    -webkit-animation-timing-function: linear;
    animation-timing-function: linear;
    animation-iteration-count: infinite;
    -webkit-animation-iteration-count: infinite;
  }
  @-webkit-keyframes bounce {
    0%, 100% {
      -webkit-transform: translateY(0);
    }
    50% {
      -webkit-transform: translateY(-5px);
    }
  }
  @keyframes bounce {
    0%, 100% {
      transform: translateY(0);
    }
    50% {
      transform: translateY(-5px);
    }
  }
  .bounce {
    -webkit-animation-name: bounce;
    animation-name: bounce;
  }
</style>
