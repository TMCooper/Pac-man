# Pac-man

## to install lazygit on ubuntu : 

- ``sudo apt-get install build-essential libssl-dev libreadline-dev zlib1g-dev
LAZYGIT_VERSION=$(curl -s "https://api.github.com/repos/jesseduffield/lazygit/releases/latest" | grep -Po '"tag_name": "v\K[^"]*')
curl -Lo lazygit.tar.gz "https://github.com/jesseduffield/lazygit/releases/latest/download/lazygit_${LAZYGIT_VERSION}_Linux_x86_64.tar.gz"
tar xf lazygit.tar.gz lazygit
sudo install lazygit /usr/local/bin``

## To install sdl : 

- ``sudo apt install libsdl2-dev``
- ``sudo apt install libsdl2-image-dev``
- ``sudo apt install libsdl2-ttf-dev ``

## Fast config git global
- ``git config --global user.name "Rias Gremory"``
- ``git config --global user.email "example@gmail.com"``
- ``git config --global user.password "your_password"``

## Install gh
- ``sudo apt install gh``

## Connection git with gh
- ``gh auth login``

## Logout
- ``gh auth logout``


### Commande pour créer l'archive `tar.gz`

Pour créer l'archive `tar.gz` contenant tous les fichiers nécessaires, utilisez la commande suivante dans le répertoire racine de votre projet :

```sh
tar -czvf pacman.tar.gz *.cpp *.h Makefile README.txt
```

to make the game on the current folder :
```sh
make
```

to luch the game : 
```sh
./pacman