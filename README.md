# table_top_maker

 QT Application for managing your table top games. This project is a way for me to learn more about C++, relational database and general GUI design.
 I decided to make a project related to table top games because it's a hobby that I've been doing for a while and wanted to create a tool that my
 DM (Dungeon Master) could use.
 
# How it should work

Table Top Maker (There's really no official name for it), is a tool to store and classify information about a fictional world, one that DM my re-use many times
for its campaigns. In this application, The fictional world is our sqlite database that is generated upon creating a new one. information such as characters, campaigns, items, etc..,
are tables in this database. For example, let's say you want to create a character. The user will be able to create characters, write their bio, relate them to different groups,
and include them in one or many campaigns. 

# What I'm doing right now

There is no gui functionality (This app is not in a working state). What I'm doing right now is setting up the "skeleton" of my application for a lack of a better word.
This means writing functions related to database queries (insert, remove, select, etc..) and eventually functions that would generate html files for the view.

# SQlite3

This Project works with the amalgammation files of sqlite3 which I have no included in this repository. Sqlite3 can be downloaded here: https://www.sqlite.org/download.html
In the root folder of the project, create a folder "lib/sqlite3", and include the files of the ammalgammation in this folder. 

# World.cpp

World.cpp currently has database transactions function which were there for test, but will be removed as soon as everything works with Database.cpp. The world is basically our database,
as one if its main role is to hold the path of our db that our transactions will be performed on.


