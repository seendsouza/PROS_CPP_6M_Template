# PROS C++ 6 Motor Template V5

Inspired by our RI3D code, I decided to make a template for the new VEX v5 system using 6 motors in the drive instead of the 4 in our RI3D. The 4 motor drive RI3D code can be found here (may be a bit worse from a programming perspective though):
* [2381C-V1](https://github.com/seendsouza/2381C-V1)

## Getting Started

I personally always use the PROS CLI and run commands from the terminal or PowerShell depending on the operating system I am using. 

### Prerequisites

First you need to install the PROS v5 CLI from the friendly developers at Purdue University:
* [pros-cli3](https://github.com/purduesigbots/pros-cli3/)

If that does not work, the developers at Purdue probably combined the legacy and the new CLI into one repository, which can be found here:
* [pros-cli](https://github.com/purduesigbots/pros-cli3/)

Note: if the repository is combined, all the commands calling the PROS-CLI should be **pros**, not **prosv5**.

### Documentation

* [PROS Documentation](https://pros.cs.purdue.edu/v5/)

## Customization

When renaming motors, make sure to rename them and their ports in all the .cpp files in the /src directory and the /include/global.h file.
**SECTION WILL BE EXPANDED SOON**

## Built With

* [PROS](https://github.com/purduesigbots/pros)

## Authors

* **Sean D'Souza** - [seendsouza](https://github.com/seendsouza)

## License

This project is licensed under the MIT License - see the [LICENSE.md](LICENSE.md) file for details
