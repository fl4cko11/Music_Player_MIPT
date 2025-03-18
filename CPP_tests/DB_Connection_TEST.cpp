#include "/home/vladh/git-repos/Music_Player_MIPT/CPP_classes/MediaPlayerController.hpp"

int main() {
    Track specialTrack{"praise", "asap", 0, 1, 0};

    std::cout << specialTrack.GetAudioPathFromDb() << std::endl;
    return 0;
}
