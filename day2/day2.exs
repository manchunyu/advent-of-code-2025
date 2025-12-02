ranges =
  File.read!("./day2input.txt")
  |> String.split(",", trim: true)
  |> Enum.map(&String.trim/1)
  |> Enum.filter(&(&1 != ""))


r =
  Enum.map(ranges, fn range ->
    range
    |> String.split("-", parts: 2)
    |> Enum.map(&String.trim/1)
    |> Enum.map(&String.to_integer/1)
  end)


IO.inspect(r)
