lines =
  File.stream!("./day3input.txt")
  |> Enum.map(&String.trim/1)

total =
  Enum.reduce(lines, 0, fn line, acc ->
    nums =
      line
      |> String.graphemes()
      |> Enum.map(&String.to_integer/1)

    max_num =
      nums
      |> Enum.drop(-1)
      |> Enum.max()

    acc + max_num
  end)




 IO.inspect(total)
