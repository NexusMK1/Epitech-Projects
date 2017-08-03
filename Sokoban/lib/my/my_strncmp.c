int	my_strncmp(char *s1, char *s2, int n)
{
  int	count;
  int	result;

  count = 0;
  result = 0;
  while (count < n)
    {
      if (s1[count] <= s2[count])
	result = result - (s2[count] - s1[count]);
      if (s1[count] >= s2[count])
	result = result + (s1[count] - s2[count]);
      if (result != 0)
	return (result);
      count = count + 1;
    }
  return (result);
}
