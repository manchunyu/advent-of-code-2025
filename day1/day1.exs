
{:ok, file} = File.open("./day1example.txt", [:read])
lines = IO.read(file, :eof) |> String.split()

hello = Enum.map(lines, fn item ->
        {dir, rest} = String.split_at(item, 1)

        num =
        if dir == "L" do
           -String.to_integer(rest)
        else
            String.to_integer(rest)
        end
        {dir, num}
    end)

password =
  Enum.reduce(hello, {0, 50}, fn {_dir, num}, {acc1, acc2} ->

    val = acc2 + rem(num, 100)

    cond do
      val in [0, 100] ->
        {acc1 + 1, 0}

      val > 99 ->
        {acc1, val - 100}

      val < 0 ->
        {acc1, 100 + val}

      true ->
        {acc1, val}
    end
  end)

password2 =
  Enum.reduce(hello, {0, 50}, fn {_dir, num}, {pw, curr} ->
    pos = curr + rem(num, 100)

    cycles = abs(trunc(num / 100))

    cond do
        pos == 0 ->
            {pw + 1 + cycles , pos}

        pos == 0 and curr == 0 ->
            {pw + cycles, pos}

        pos >= 100 ->
            {pw + 1 + cycles, pos - 100}

        pos < 0 and curr ==0 ->
            {pw + cycles , 100 + pos}

        pos < 0 and curr != 0 ->
            {pw + cycles + 1, 100 + pos }


        true ->
            {pw + cycles, pos}

    end
  end)

IO.inspect(password2)
