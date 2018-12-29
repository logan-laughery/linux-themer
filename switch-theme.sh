#! /bin/bash
parent_path=$( cd "$(dirname "${BASH_SOURCE[0]}")" ; pwd -P )
echo $parent_path

# Execute the prompt and record return value
"$parent_path"/build/linux-unpacked/linux-themer-electron
selection=$?
echo $selection

if [ "$selection" -eq 1 ]; then
    echo "Light Theme"
    cp -r "$parent_path"/dotfiles/light/. "$HOME"/.config/
elif [ "$selection" -eq 2 ]; then
    echo "Dark Theme"
    cp -r "$parent_path"/dotfiles/dark/. "$HOME"/.config/
else
    echo "Unknown return code: $selection"
fi
