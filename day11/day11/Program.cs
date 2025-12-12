using System.Collections;

class Program
{
    public static void Main(string[] args)
    {
        StreamReader reader = new StreamReader(args[0]);

        Dictionary<string,List<string>> map = new Dictionary<string, List<string>>();
        HashSet<string> visited = new HashSet<string>();
        Dictionary<string, int> cache = new Dictionary<string, int>();

        string line;
        while (null != (line = reader.ReadLine()))
        {
            List<string> parts =  line.Split(":").ToList();
            string source = parts[0];
            List<string> destination = parts[1].Trim().Split(" ").ToList();
            
            // Console.WriteLine($"From:{deviceName}");
            // foreach (var device in deviceTo)
            // {
            //     Console.WriteLine($"To:{device}");
            // }
            map.Add(key:source, value:destination);
        }

        // foreach (DictionaryEntry item in map)
        // {
        //     Console.WriteLine($"{item.Key}: {string.Join(", ", (List<string>)item.Value)}");
        // }
        long pathCounter = 0;
        string start = "you";
        string end = "out";
        long FindPath(string from)
        {
            if (from == end)
            {
                return 1;
            }

            if (visited.Contains(from))
            {
                return 0;
            }

            if (cache.TryGetValue(from, out int cached))
            {
                return cached;
            }

            visited.Add(from);

            long total = 0;

            foreach (string to in map[from])
            {
                total += FindPath(to);
            }

            visited.Remove(from);
            return total;
            
        }

        pathCounter = FindPath(start);

        Console.WriteLine(pathCounter);

    }

    
}







// public readonly struct Device
// {
//     public Device(string name, string[] to)
//     {
//         Name = name;
//         To = to;
//     }
//     
//     public string Name { get; init; }
//     public string[] To { get; init; }
//
//     public override string ToString() => $"Name:{Name}, To: {string.Join(", ", To)}";
