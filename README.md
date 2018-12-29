# linux-themer-electron

> A simple prompt for switching linux themes.

#### Build Setup

``` bash
# install dependencies
npm install

# serve with hot reload at localhost:9080
npm run dev

# build electron application for production
npm run build


# lint all JS/Vue component files in `src/`
npm run lint

```

#### Setting up dotfiles
This repo copies dotfiles found in `dotfiles/light/` and `dotfiles/dark/`
to `$HOME/.config/` based on the selection made in the prompt.  To be part of a theme, 
applications will need to look for dotfiles in `$HOME/.config`.

#### Starting Prompt On Boot
Build the linux electron prompt:
`npm run build`

Execute this repositories bash script in `~/.xinitrc`:
```
#! /bin/bash
/home/logan/Development/linux-themer/switch-theme.sh
exec i3
```

---

This project was generated with [electron-vue](https://github.com/SimulatedGREG/electron-vue)@[8fae476](https://github.com/SimulatedGREG/electron-vue/tree/8fae4763e9d225d3691b627e83b9e09b56f6c935) using [vue-cli](https://github.com/vuejs/vue-cli). Documentation about the original structure can be found [here](https://simulatedgreg.gitbooks.io/electron-vue/content/index.html).
