# MediaManagementSystem
Generic file management API, implemented with static song objects

## Getting Started

These instructions will get you a copy of the project up and running on your local machine for development and testing purposes. 
Clone the ReleaseVersion branch (https://github.com/YLeventhal/MediaManagementSystem/tree/ReleaseVersion) to your device.

### Instructions

Instantiate a MySongs object to hold your collection of songs and folders. Your object has a Folders list 
and a Songs list. A Folder from the list could contain inner folders ad infinitum. 
Use your objects methods to add/remove/move/play songs and to add/remove folders or to print a folders content.


```
MySongs myFavoriteSongs;

mySongs.AddFolder("Reggae");

// adding an inner folder to the reggae folder for specific artists.
mySongs.AddFolder("Bob Marley", "Reggae");

// add a song to the inner folder. Parameters are  title, artist, lyrics and folder to add to.
mySongs.AddSong("No Woman No Cry", "Bob Marley", "No Woman No Cry...", "Bob Marley");

```



## Running the tests

A driver has been included with hard coded testing. You can replace the song names, lyrics and artist with your own.

### Break down into end to end tests

Explain what these tests test and why

```
Give an example
```


## Built With

 * Visual Studio version 2017

## Authors

  **Yehoshua Leventhal** -- (https://github.com/YLeventhal)


## License

This project is licensed under the MIT License - see the [LICENSE.md](LICENSE.md) file for details

