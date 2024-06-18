# So Long

So Long is a simple 2D game. The player controls a character that can move through the map, collect collectibles, and avoid enemies. The player wins when all collectibles are collected, and the player loses when the character collides with an enemy.

## Table of Contents

- [About](#about)
- [Getting Started](#getting-started)
  - [Prerequisites](#prerequisites)
  - [Installing](#installing)
- [Running the tests](#running-the-tests)
- [Usage](#usage)
- [Built Using](#built-using)
- [Authors](#authors)
- [Acknowledgements](#acknowledgements)
- [License](#license)

## About

So Long is a simple 2D game. Game engine is implemented using C and the [MLX](https://harm-smits.github.io/42docs/libs/minilibx) library. The game has a map with walls, collectibles, and enemies. The player controls a character that can move through the map, collect collectibles, and avoid enemies. The player wins when all collectibles are collected, and the player loses when the character collides with an enemy.

## Getting Started

These instructions will get you a copy of the project up and running on your local machine for development and testing purposes.

### Prerequisites

What things you need to install the software and how to install them.

```text
gcc >= 7.5.0
make >= 4.1
```

```bash
sudo apt-get install gcc
sudo apt-get install make
```

### Installing

A step by step series of examples that tell you how to get a development env running.

Clone the repository.

```bash
git clone https://github.com/LudwigAndreas/so_long

cd so_long
```

Build the project.

```bash
make
```

Run the project.

```bash
./so_long resources/maps/valid_maps/map.ber
```

## Running the tests

Explain how to run the automated tests for this system.

```bash
make test
```

## Usage

After running the project, the game window will open. The player can control the character using the arrow keys. The player can collect collectibles and avoid enemies. The player wins when all collectibles are collected, and the player loses when the character collides with an enemy. The player can close the game window by clicking the close button.

## Built Using

- [C](https://en.wikipedia.org/wiki/C_(programming_language)) - Programming language
- [MLX](https://harm-smits.github.io/42docs/libs/minilibx) - Library
- [Make](https://en.wikipedia.org/wiki/Make_(software)) - Build automation tool

## Authors

This project was developed by:

| <img src="https://avatars.githubusercontent.com/u/88089961?v=4" alt="drawing" width="50"/> |[LudwigAndreas](https://github.com/LudwigAndreas)|
| --- | --- |

## Acknowledgements

- [School 21](https://21-school.ru/) - Educational institution
- [42](https://www.42.fr/) - Educational institution

## License

This project is licensed under the School 21 License - see the [LICENSE](LICENSE) file for details.
