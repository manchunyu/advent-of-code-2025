using System.Numerics;

class Program
{
    static void Main(string[] args)
    {
        using var reader = new StreamReader(args[0]);

        var boxes = new List<Vector3>();
        var edges = new List<Edge>();

        string line;
        while ((line = reader.ReadLine()) != null)
        {
            float[] coordinates = line.Split(',').Select(float.Parse).ToArray();

            var newBox = new Vector3(coordinates[0], coordinates[1], coordinates[2]);

            foreach (var box in boxes)
            {
                edges.Add(new Edge(box, newBox));
            }

            boxes.Add(newBox);
        }

        foreach (var edge in edges)
        {
            Console.WriteLine(edge);
        }
    }
}

public class Edge
{
    public Vector3 From;
    public Vector3 To;
    public readonly float Distance;

    public Edge(Vector3 from, Vector3 to)
    {
        From = from;
        To = to;
        Distance = Vector3.Distance(from, to);
    }

    public override string ToString()
    {
        return $"{From} -> {To} (dist = {Distance})";
    }
}