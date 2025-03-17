CREATE TABLE Tracks (
    Track_Name text,
    Artist_Name text,
    Path_to_audio text,
    Path_to_image text,
    Listening int,
    PRIMARY KEY (Track_Name, Artist_Name)
);
