enum Direction { North, South, East, West };

class MapSite {
  virtual void Enter() = 0;
};

class Maze {
public:
  Maze();

  void AddRoom();
  Room *RoomNo(int) const;
};

class Room : public MapSite {
public:
  Room(int roomNo);

  MapSite *GetSide(Direction) const;
  void SetSide(Direction, MapSite *);

  virtual void Enter();

private:
  MapSite *_sides[4];
  int _roomNumer;
};

class Wall : public MapSite {
public:
  Wall();

  virtual void Enter();
};

class Door : public MapSite {
public:
  Door(Room * = 0, Room * = 0);

  virtual void Enter();
  Room *OtherSideFrom(Room *);

private:
  Room *_room1;
  Room *_room2;
  bool _isOpen;
};

int main() {}