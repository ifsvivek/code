import time
import matplotlib.pyplot as plt
from pynput.mouse import Listener

class PollingRateCalculator:
    def __init__(self):
        self.event_count = 0
        self.start_time = time.time()
        self.last_time = self.start_time
        self.polling_rates = []
        self.highest_polling_rate = 0

    def on_move(self, x, y):
        self.event_count += 1
        current_time = time.time()
        elapsed_time = current_time - self.last_time
        if elapsed_time >= 1:
            polling_rate = self.event_count / elapsed_time
            self.polling_rates.append(polling_rate)
            self.last_time = current_time
            self.event_count = 0
            self.highest_polling_rate = max(self.highest_polling_rate, polling_rate)
            self.update_graph()

    def update_graph(self):
        plt.clf()
        plt.plot(self.polling_rates, label='Polling Rate')
        plt.axhline(self.highest_polling_rate, color='r', linestyle='dashed', label='Highest Polling Rate')
        plt.xlabel('Time (s)')
        plt.ylabel('Polling Rate (events per second)')
        plt.title('Mouse Polling Rate')
        plt.legend()
        plt.pause(0.01)

    def start(self):
        with Listener(on_move=self.on_move) as listener:
            plt.ion()  # Turn on interactive mode for plotting
            plt.show()
            listener.join()

if __name__ == "__main__":
    calculator = PollingRateCalculator()
    calculator.start()
