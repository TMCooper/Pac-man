# Pac-man

## to install lazygit on ubuntu : 
LAZYGIT_VERSION=$(curl -s "https://api.github.com/repos/jesseduffield/lazygit/releases/latest" | grep -Po '"tag_name": "v\K[^"]*')
curl -Lo lazygit.tar.gz "https://github.com/jesseduffield/lazygit/releases/latest/download/lazygit_${LAZYGIT_VERSION}_Linux_x86_64.tar.gz"
tar xf lazygit.tar.gz lazygit
sudo install lazygit /usr/local/bin

## to install sdl : 

- ``sudo apt install libsdl2-dev``
- sudo apt install libsdl2-image-dev
- sudo apt install libsdl2-ttf-dev 

## Fast config git global
- git config --global user.name "Mona Lisa"
- git config --global user.email "example@gmail.com"
- git config --global user.password "your_password"