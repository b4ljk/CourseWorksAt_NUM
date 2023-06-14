# decompyle3 version 3.9.0
# Python bytecode version base 3.7.0 (3394)
# Decompiled from: Python 3.8.2 (default, Mar 26 2020, 10:43:30) 
# [Clang 4.0.1 (tags/RELEASE_401/final)]
# Embedded file name: /home/classes/cs470/hws/hw1/.answer/hw1a.py
# Compiled at: 2020-01-22 04:32:13
# Size of source mod 2**32: 6920 bytes
from showprops import *
from agents import *

def hours():
    return 2


class NewVacuumEnvironment(VacuumEnvironment):

    def __init__(self, width=5, height=5, bias=0.5):
        super().__init__(width, height)
        self.bias = bias
        self.add_walls()
        self.add_random_dirt()

    def add_random_dirt(self):
        for x in range(self.x_start, self.x_end):
            for y in range(self.y_start, self.y_end):
                if random.random() < self.bias:
                    self.add_thing(Dirt(), (x, y), True)

    def get_world(self):
        """Returns all the items in the world in a format
        understandable by the ipythonblocks BlockGrid."""
        result = []
        x_start, y_start = (0, 0)
        x_end, y_end = self.width, self.height
        for x in range(x_start, x_end):
            row = []
            for y in range(y_start, y_end):
                row.append(self.list_things_at((x, y)))

            result.append(row)

        return result

    def execute_action(self, agent, action):
        """Change agent's location and/or location's status; track performance.
        Score 10 for each dirt cleaned; -1 for each move."""
        x, y = agent.location
        if action == 'Right':
            if x + 1 < self.width:
                agent.location = (
                 x + 1, y)
            agent.performance -= 1
        else:
            if action == 'Left':
                if x > 1:
                    agent.location = (
                     x - 1, y)
                agent.performance -= 1
            else:
                if action == 'Up':
                    if y > 1:
                        agent.location = (
                         x, y - 1)
                    agent.performance -= 1
                else:
                    if action == 'Down':
                        if y + 1 < self.height:
                            agent.location = (
                             x, y + 1)
                        agent.performance -= 1
                    else:
                        if action == 'Suck':
                            if self.list_things_at(agent.location, Dirt):
                                agent.performance += 10
                                self.delete_thing(self.list_things_at(agent.location, Dirt)[0])


class GraphicVacuumEnvironment(NewVacuumEnvironment):

    def __init__(self, width=10, height=10, bias=0.5, boundary=True, color={}, display=False):
        """Define all the usual XYEnvironment characteristics,
        but initialise a BlockGrid for GUI too."""
        super().__init__(width, height, bias=bias)
        self.grid = BlockGrid(width, height, fill=(200, 200, 200))
        if display:
            self.grid.show()
            self.visible = True
        else:
            self.visible = False
        self.bounded = boundary
        self.colors = color

    def run(self, steps=1000, delay=1):
        """Run the Environment for given number of time steps,
        but update the GUI too."""
        for step in range(steps):
            self.update(delay)
            if self.is_done():
                break
            else:
                self.step()

        self.update(delay)

    def update(self, delay=1):
        sleep(delay)
        if self.visible:
            self.conceal()
            self.reveal()
        else:
            self.reveal()

    def reveal(self):
        """Display the BlockGrid for this world - the last thing to be added
        at a location defines the location color."""
        self.draw_world()
        self.grid.show()
        self.visible = True

    def draw_world(self):
        self.grid[:] = (200, 200, 200)
        world = self.get_world()
        for x in range(0, len(world)):
            for y in range(0, len(world[x])):
                if len(world[x][y]):
                    self.grid[(y, x)] = self.colors[world[x][y][-1].__class__.__name__]

    def conceal(self):
        """Hide the BlockGrid for this world"""
        self.visible = False
        display(HTML(''))


def BetterReflexVacuumAgent():
    """A reflex agent for the XY vacuum environment. 
    >>> agent = BetterReflexVacuumAgent()
    >>> environment = TrivialVacuumEnvironment()
    >>> environment.add_thing(agent)
    """

    def program(percept):
        status, location = percept
        if status == 'Dirty':
            return 'Suck'
        return random.choice(['Left', 'Right', 'Up', 'Down'])

    return Agent(program)


def TraceAgent(agent):
    """Wrap the agent's program to print its input and output. This will let
    you see what the agent is doing in the environment."""
    old_program = agent.program

    def new_program(percept):
        action = old_program(percept)
        print('{} perceives {} and does {} at {}'.format(agent, percept, action, agent.location))
        return action

    agent.program = new_program
    return agent


def test(got, expected):
    if hasattr(expected, '__call__'):
        OK = expected(got)
    else:
        OK = got == expected
    if OK:
        prefix = ' OK '
    else:
        prefix = '  X '
    print('%s got: %s expected: %s' % (prefix, repr(got), repr(expected)))


def main():
    print('hours')
    print('# is it greater than 0?')
    test(hours(), lambda x: x > 0)
    print('NewVacuumEnvironment - Walls')
    testnve = NewVacuumEnvironment(5, 5, bias=0.0)
    x = testnve.get_world()
    test(str(x), '[[[<Wall>], [<Wall>], [<Wall>], [<Wall>], [<Wall>]], [[<Wall>], [], [], [], [<Wall>]], [[<Wall>], [], [], [], [<Wall>]], [[<Wall>], [], [], [], [<Wall>]], [[<Wall>], [<Wall>], [<Wall>], [<Wall>], [<Wall>]]]')
    print('NewVacuumEnvironment - Dirt')
    testnve = NewVacuumEnvironment(20, 20, bias=0.5)
    x = testnve.get_world()
    s = str(x)
    ss = s.split(', ')
    sss = [x for x in ss if x == '[<Dirt>]']
    test(len(sss), lambda x: 140 < x < 184)
    print('NewVacuumEnvironment - Very Clean')
    testnve = NewVacuumEnvironment(20, 20, bias=0.0)
    x = testnve.get_world()
    s = str(x)
    ss = s.split(', ')
    sss = [x for x in ss if x == '[<Dirt>]']
    test(len(sss), 0)
    print('NewVacuumEnvironment - Very Dirty')
    testnve = NewVacuumEnvironment(20, 20, bias=1.0)
    x = testnve.get_world()
    s = str(x)
    ss = s.split(', ')
    sss = [x for x in ss if x == '[<Dirt>]']
    test(len(sss), 324)
    print('TraceAgent and BetterReflexVacuumAgent')
    testbrva = TraceAgent(BetterReflexVacuumAgent())
    testnve.add_thing(testbrva)
    testnve.run(1)
    test(testbrva.location, (1, 1))
    test(testbrva.performance, 10)
    testnve.run(20)
    test(testbrva.performance, lambda x: x > 30)
