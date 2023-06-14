namespace CalcLib
{
    public abstract class Calculator
    {
        /// <summary>
        /// Calculatoriin odoogiin hariu
        /// </summary>
        public int Result { get; set; }
        public int a, b;
        public string? command;
    }

    public interface ICalculator
    {
        /// <summary>
        /// 2 тоог нэмнэ
        /// </summary>
        /// <param name="x">Нэмэх эхний тоо</param>
        /// <param name="y">Нэмэх 2 дох тоо</param>
        void Add(int x, int y);

        /// <summary>
        /// 2 тоог хасна
        /// </summary>
        /// <param name="x">Хасах тоо</param>
        /// <param name="y">Хасагдагч тоо</param>
        void Subtract(int x, int y);
    }


    public class MainCalculator : Calculator, ICalculator
    {
        public Memory _memory = new Memory();

        public MainCalculator() {
            Result = 0;
        }

        public void MemoryClear()
        {
            _memory._memoryItems = null;
        }

        /// <summary>
        /// 2 тоог нэмнэ
        /// </summary>
        /// <param name="x">Нэмэх эхний тоо</param>
        /// <param name="y">Нэмэх 2 дох тоо</param>
        public void Add(int x, int y)
        {
            Result = x + y;
        }

        /// <summary>
        /// 2 тоог хасна
        /// </summary>
        /// <param name="x">Хасах тоо</param>
        /// <param name="y">Хасагдагч тоо</param>
        public void Subtract(int x, int y)
        {
            Result = x - y;
        }

        /// <summary>
        /// item-ийг мемори луу нэмнэ
        /// </summary>
        /// <param name="item">нэмэх item</param>
        public void AddMemoryItem(MemoryItem item)
        {
            _memory.AddMemoryItem(item);
        }

        /// <summary>
        /// item-ийг мемори гаас хасна
        /// </summary>
        /// <param name="item">Хасах item</param>
        public void RemoveMemoryItem(MemoryItem item)
        {
            _memory.RemoveMemoryItem(item);
        }

        public void GetMemoryItem(MemoryItem item) { 
           
        }
    }

    public class Memory
    {
        /// <summary>
        /// Мемори гишүүд
        /// </summary>
        public List<MemoryItem>? _memoryItems = new List<MemoryItem>();

        /// <summary>
        /// item-ийг мемори луу нэмнэ
        /// </summary>
        /// <param name="item">нэмэх item</param>
        public void AddMemoryItem(MemoryItem item)
        {
            _memoryItems?.Add(item);
        }

        /// <summary>
        /// item-ийг мемори гаас хасна
        /// </summary>
        /// <param name="item">Хасах item</param>
        public void RemoveMemoryItem(MemoryItem item)
        {
            _memoryItems?.Remove(item);
        }
    }

    /// <summary>
    /// Тооны машины мемори луу нэмж болох item
    /// </summary>
    public class MemoryItem : Calculator, ICalculator
    {
        /// <summary>
        /// 2 тоог нэмнэ
        /// </summary>
        /// <param name="x">Нэмэх эхний тоо</param>
        /// <param name="y">Нэмэх 2 дох тоо</param>
        public void Add(int x, int y)
        {
            Result = x + y;
        }

        /// <summary>
        /// 2 тоог хасна
        /// </summary>
        /// <param name="x">Хасах тоо</param>
        /// <param name="y">Хасагдагч тоо</param>
        public void Subtract(int x, int y)
        {
            Result = x - y;
        }
    }
}