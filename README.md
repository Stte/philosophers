# Philosophers Problem Simulation

This project is a simulation of the classic philosophers problem, where a group of philosophers sit around a table with a bowl of rice and chopsticks. The philosophers spend their time thinking and eating. A philosopher needs both chopsticks to eat and must put them down before they can resume eating. The challenge is to design a protocol that allows the philosophers to eat without starving, i.e., ensuring that no philosopher will starve while at least one philosopher is eating.

## Features

- Simulates the philosophers problem with a configurable number of philosophers.
- Each philosopher can eat, sleep, and think.
- The simulation includes mechanisms to prevent deadlocks and ensure that philosophers can eat.
- Configurable parameters for the simulation, such as the number of philosophers, time to eat, sleep, and die.

## Getting Started

### Prerequisites

- A C compiler (e.g., gcc)
- POSIX threads library (pthread)

### Installation

1. Clone the repository: `git clone https://github.com/Stte/philosophers.git`

2. Navigate to the project directory: `cd philosophers`

3. Compile the project: `make`

### Running the Simulation

To run the simulation, use the following command:

./philosophers <number_of_philosophers> <time_to_die> <time_to_eat> <time_to_sleep> [times_must_eat]

- `<number_of_philosophers>`: The number of philosophers at the table.
- `<time_to_die>`: The time in milliseconds after which a philosopher will die of starvation.
- `<time_to_eat>`: The time in milliseconds a philosopher spends eating.
- `<time_to_sleep>`: The time in milliseconds a philosopher spends sleeping.
- `[times_must_eat]`: (Optional) The number of times a philosopher must eat before they can die. If not provided, the simulation will run until a philosopher dies of starvation.

## Acknowledgments

- The classic philosophers problem as a synchronization problem.
- The use of POSIX threads for implementing the simulation.

We pair coded ~80% of this project with [RushMaverick](https://github.com/RushMaverick), [Nick van den Dungen](https://github.com/Nicktvdd) and [Kimpozer](https://github.com/composerjunhee) using VS code Live Share.

**Error codes**

- 1 args wrong
- 2 attrs wrong
- 3 mutex init failed
- 4 mutex destroy failed
