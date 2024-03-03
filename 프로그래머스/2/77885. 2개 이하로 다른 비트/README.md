# [level 2] 2개 이하로 다른 비트 - 77885 

[문제 링크](https://school.programmers.co.kr/learn/courses/30/lessons/77885) 

### 성능 요약

메모리: 27.8 MB, 시간: 32.42 ms

### 구분

코딩테스트 연습 > 월간 코드 챌린지 시즌2

### 채점결과

정확성: 100.0<br/>합계: 100.0 / 100.0

### 제출 일자

2024년 03월 03일 20:36:08

### 문제 설명

<p>양의 정수 <code>x</code>에 대한 함수 <code>f(x)</code>를 다음과 같이 정의합니다.</p>

<ul>
<li><code>x</code>보다 크고 <code>x</code>와 <strong>비트가 1~2개 다른</strong> 수들 중에서 제일 작은 수</li>
</ul>

<p>예를 들어, </p>

<ul>
<li><code>f(2) = 3</code> 입니다. 다음 표와 같이 2보다 큰 수들 중에서 비트가 다른 지점이 2개 이하이면서 제일 작은 수가 3이기 때문입니다.</li>
</ul>
<table class="table">
        <thead><tr>
<th>수</th>
<th>비트</th>
<th>다른 비트의 개수</th>
</tr>
</thead>
        <tbody><tr>
<td>2</td>
<td><code>000...0010</code></td>
<td></td>
</tr>
<tr>
<td>3</td>
<td><code>000...0011</code></td>
<td>1</td>
</tr>
</tbody>
      </table>
<ul>
<li><code>f(7) = 11</code> 입니다. 다음 표와 같이 7보다 큰 수들 중에서 비트가 다른 지점이 2개 이하이면서 제일 작은 수가 11이기 때문입니다.</li>
</ul>
<table class="table">
        <thead><tr>
<th>수</th>
<th>비트</th>
<th>다른 비트의 개수</th>
</tr>
</thead>
        <tbody><tr>
<td>7</td>
<td><code>000...0111</code></td>
<td></td>
</tr>
<tr>
<td>8</td>
<td><code>000...1000</code></td>
<td>4</td>
</tr>
<tr>
<td>9</td>
<td><code>000...1001</code></td>
<td>3</td>
</tr>
<tr>
<td>10</td>
<td><code>000...1010</code></td>
<td>3</td>
</tr>
<tr>
<td>11</td>
<td><code>000...1011</code></td>
<td>2</td>
</tr>
</tbody>
      </table>
<p>정수들이 담긴 배열 <code>numbers</code>가 매개변수로 주어집니다. <code>numbers</code>의 모든 수들에 대하여 각 수의 <code>f</code> 값을 배열에 차례대로 담아 return 하도록 solution 함수를 완성해주세요.</p>

<hr>

<h5>제한사항</h5>

<ul>
<li>1 ≤ <code>numbers</code>의 길이 ≤ 100,000</li>
<li>0 ≤ <code>numbers</code>의 모든 수 ≤ 10<sup>15</sup></li>
</ul>

<hr>

<h5>입출력 예</h5>
<table class="table">
        <thead><tr>
<th>numbers</th>
<th>result</th>
</tr>
</thead>
        <tbody><tr>
<td><code>[2,7]</code></td>
<td><code>[3,11]</code></td>
</tr>
</tbody>
      </table>
<hr>

<h5>입출력 예 설명</h5>

<p><strong>입출력 예 #1</strong></p>

<ul>
<li>문제 예시와 같습니다.</li>
</ul>

<hr>
<h2>풀이</h2>
<p>짝수와 홀수로 구분해서 풀어야 한다. 짝수인 경우 항상 맨 뒤 비트가 0이기 때문에, 무조건 1을 더해주면 비트가 1개만 바뀌면서 현재 수보다 큰 수중에 가장 작은수가 되므로 짝수+1을 한 것이 답이된다.
홀수의 경우는, 2진수로 표현했을 때, 연속되는 1의 비트 자릿수를 구하고 해당 자릿수에 대한 1을 더해주면 해당 자릿수는 0이되고 그 다음 자릿수는 1이 되면서 비트가 2개만 바뀌면서 현재 수보다 큰 수중에 가장 작은 수가 되므로 이것이 답이된다. 예를 들어 3의 경우 0011로 표현할 수 있고 연속되는 1의 개수가 2개이므로 0010을 더해주면 0101이 되면서 조건에 알맞는 수가 된다. 00111은 00100을 더해주면 010111이 된다. </p>
<p>기본 원리는 위와 같고, 코드의 경우는 while ((number & bit) > 0) 이 반복문을 통해 비트를 하나씩 시프트하며 연속된 1이 끝나는 자릿수를 찾아낸다.예를 들어 0111일 때, 연속된 1이 끝나는 자릿수의 1 즉, 1000과 연산하면 0000 = 0 이 되는 것을 활용한다. 그 다음에는 우리가 원하는 연산은 연속된 1의 마지막 자릿수니까, 끝나는 자릿수에서 반대로 시프트 하나 해주고 이에 대한 1을 더해주면 답이 된다.</p>

> 출처: 프로그래머스 코딩 테스트 연습, https://school.programmers.co.kr/learn/challenges
