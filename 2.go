package main

import (
	"fmt"
	"os"
)

// NodeQ представляет узел очереди
type NodeQ struct {
	data int
	next *NodeQ
}

// Queue представляет саму очередь
type Queue struct {
	head *NodeQ
	tail *NodeQ
}

// NewQueue создает и возвращает новую очередь
func NewQueue() *Queue {
	return &Queue{}
}

// Метод для добавления элемента в очередь
func (q *Queue) Push(value int) {
	newNode := &NodeQ{data: value, next: nil}
	if q.tail == nil { // Если очередь пуста
		q.head = newNode
		q.tail = newNode
	} else {
		q.tail.next = newNode // Добавляем новый узел в конец
		q.tail = newNode      // Обновляем указатель на хвост
	}
}

// Метод для удаления элемента из очереди
func (q *Queue) Pop() (int, error) {
	if q.head == nil {
		return 0, fmt.Errorf("очередь пуста")
	}
	temp := q.head
	q.head = q.head.next
	if q.head == nil { // Если очередь стала пустой
		q.tail = nil
	}
	value := temp.data
	return value, nil
}

// Метод для вывода всех элементов очереди
func (q *Queue) Print() {
	current := q.head
	if current == nil {
		fmt.Println("Очередь пуста.")
		return
	}
	for current != nil {
		fmt.Printf("%d ", current.data)
		current = current.next
	}
	fmt.Println()
}

// Метод для очистки очереди
func (q *Queue) ClearQueue() {
	for q.head != nil {
		_, _ = q.Pop() // Удаляем все элементы очереди
	}
}

// Метод для записи элементов очереди в файл
func (q *Queue) WriteToFile(filename string) error {
	file, err := os.Create(filename) // Создаем (или перезаписываем) файл
	if err != nil {
		return fmt.Errorf("не удалось открыть файл для записи: %v", err)
	}
	defer file.Close()

	current := q.head
	for current != nil {
		_, err := fmt.Fprintf(file, "%d\n", current.data) // Записываем каждый элемент в файл
		if err != nil {
			return fmt.Errorf("не удалось записать в файл: %v", err)
		}
		current = current.next
	}
	return nil
}

// Главная функция программы
func main() {
	queue := NewQueue()

	for {
		// Ввод команды
		fmt.Print(">> ")

		var choice string
		var value int
		_, err := fmt.Scanf("%s", &choice) // Считываем команду

		if err != nil {
			fmt.Println("Ошибка ввода! Попробуйте снова.")
			continue
		}

		// Если команда требует числа (QPUSH), считываем и число
		if choice == "QPUSH" {
			_, err := fmt.Scanf("%d", &value) // Считываем число для QPUSH
			if err != nil {
				fmt.Println("Ошибка ввода числа! Попробуйте снова.")
				continue
			}
		}

		// Обработка выбранного действия
		switch choice {
		case "QPUSH":
			queue.Push(value)                    // Используем метод Push
			err = queue.WriteToFile("Queue.txt") // Записываем очередь в файл после добавления
			if err != nil {
				fmt.Println("Ошибка записи в файл:", err)
			}
		case "QPOP":
			value, err := queue.Pop() // Используем метод Pop
			if err != nil {
				fmt.Println(err)
			} else {
				fmt.Printf("Удален элемент: %d\n", value)
			}
			err = queue.WriteToFile("Queue.txt") // Записываем очередь в файл после удаления
			if err != nil {
				fmt.Println("Ошибка записи в файл:", err)
			}
		case "QPRINT":
			fmt.Println("Элементы очереди: ")
			queue.Print() // Используем метод Print
		case "EXIT":
			queue.ClearQueue() // Используем метод ClearQueue
			fmt.Println("Выход из программы.")
			os.Exit(0)
			break
		default:
			fmt.Println("Неверный выбор, попробуйте снова.")
		}
	}
}
