class Hormiga:
    ORIENT_LEFT  = 0
    ORIENT_RIGHT = 1
    poleLength = 0
    orientation = 0
    pos = 0

    def Hormiga(orient,pos):
        self.orientation = int(orient)
        self.pos = int(pos)


    def is_on_pole():
        return bool(pos > 0 and pos < poleLength)
