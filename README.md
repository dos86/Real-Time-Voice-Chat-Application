# Real-Time-Voice-Chat-Application

#### Overview:
This project is a real-time voice chat application where users can communicate over a network using their microphones. The application uses **UDP** for low-latency audio transmission, making it suitable for real-time communication. The GUI is built using **Qt**, providing an intuitive interface for managing connections, muting/unmuting the microphone, and adjusting volume levels.

---

### Key Features:
1. **Client-Server Architecture**:
   - The server acts as a relay, forwarding audio packets from one client to all other connected clients.
   - Clients connect to the server via UDP sockets.

2. **Real-Time Audio Streaming**:
   - Audio is captured from the user's microphone and transmitted in real-time using low-latency UDP.
   - Received audio packets are played back using Qt's multimedia framework.

3. **GUI Components**:
   - **Connect/Disconnect Buttons**: Allow users to join or leave the chat room.
   - **Mute/Unmute Button**: Toggle the microphone on/off.
   - **Volume Control**: Adjust the playback volume of incoming audio.
   - **Status Display**: Show connection status and active participants.

4. **Multithreading**:
   - Separate threads handle audio capture, audio playback, and network communication to ensure smooth performance.

5. **Error Handling**:
   - Handle disconnections gracefully.
   - Provide feedback for errors such as failed connections or missing audio devices.

---

### Technologies Used:
1. **STL**: `std::vector`, `std::thread`, `std::mutex`.
2. **OOP**: Encapsulation and modularity in designing `AudioCapture`, `AudioPlayback`, `Client`, and `Server` classes.
3. **Multithreading**: Concurrent handling of audio capture, playback, and network communication.
4. **Networking**: UDP sockets for real-time audio streaming.
5. **GUI Framework**: Qt for building the graphical user interface.
6. **Audio Processing**: Qt Multimedia for capturing and playing back audio.

---

### Folder Structure:
```
VoiceChatApp/
├── include/
│   ├── AudioCapture.hpp       // Audio capture class
│   ├── AudioPlayback.hpp      // Audio playback class
│   ├── Client.hpp             // Client class definition
│   ├── Server.hpp             // Server class definition
│   └── MainWindow.hpp         // Main GUI window
├── src/
│   ├── AudioCapture.cpp
│   ├── AudioPlayback.cpp
│   ├── Client.cpp
│   ├── Server.cpp
│   └── MainWindow.cpp
├── main.cpp                   // Main entry point
├── CMakeLists.txt             // Build configuration
└── README.md                  // Project documentation
```

---

### Workflow:
1. **Server**:
   - Listens for incoming UDP packets from clients.
   - Broadcasts received audio packets to all connected clients.

2. **Client**:
   - Captures audio from the microphone using Qt Multimedia.
   - Sends captured audio packets to the server via UDP.
   - Receives audio packets from the server and plays them back using Qt Multimedia.

3. **GUI**:
   - Provides buttons to connect/disconnect, mute/unmute, and adjust volume.
   - Displays the connection status and active participants.

---

### Example Use Case:
- A user starts the server application.
- Multiple clients launch the GUI-based client application and connect to the server.
- Users can speak into their microphones, and their voices are transmitted in real-time to all other connected clients.
- Users can mute their microphones, adjust the volume, or disconnect from the chat.
