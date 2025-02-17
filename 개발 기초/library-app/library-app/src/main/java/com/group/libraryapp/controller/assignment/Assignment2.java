package com.group.libraryapp.controller.assignment;

import com.group.libraryapp.dto.assignment.request.FruitInformationRequest;
import com.group.libraryapp.dto.assignment.request.FruitUpdateRequest;
import com.group.libraryapp.dto.assignment.response.FruitSellMoney;
import com.group.libraryapp.dto.calculator.request.CalculatorSumRequest;
import com.group.libraryapp.dto.calculator.response.CalculateResponse;
import com.group.libraryapp.dto.calculator.response.DateResponse;
import org.springframework.format.annotation.DateTimeFormat;
import org.springframework.jdbc.core.JdbcTemplate;
import org.springframework.web.bind.annotation.*;

import java.time.LocalDate;
import java.util.ArrayList;

@RestController
public class Assignment2 {

    private final JdbcTemplate jdbcTemplate;

    public Assignment2(JdbcTemplate jdbcTemplate) {
        this.jdbcTemplate = jdbcTemplate;
    }

    @GetMapping("/api/v1/calc")
    public CalculateResponse calculate(@RequestParam Integer num1, @RequestParam Integer num2) {
        CalculateResponse responses = new CalculateResponse(num1+num2, num1 - num2 , num1 * num2);
        return responses;
    }


    @GetMapping("/api/v1/day-of-the-week")
    public DateResponse dayOfTheWeek(@RequestParam @DateTimeFormat(iso = DateTimeFormat.ISO.DATE) LocalDate date){

        return new DateResponse(date.getDayOfWeek());
    }

    @PostMapping("api/v1/sum")
    public Integer sum(@RequestBody CalculatorSumRequest request) {
        Integer sum = 0;
        ArrayList <Integer> numbers = request.getNumbers();


        for(int i = 0 ; i < numbers.size() ; i++){
            sum += numbers.get(i);
        }
        return sum;
    }

    @PostMapping("/api/v1/fruit")
    public void fruitSave(@RequestBody FruitInformationRequest request) {
        String sql = "INSERT INTO fruit (name, warehousingDate, price) VALUES (?, ?, ?)";
        jdbcTemplate.update(sql, request.getName() , request.getWarehousingDate(), request.getPrice());

    }

    @PutMapping("/api/v1/fruit")
    public void fruitUpdate(@RequestBody FruitUpdateRequest request) {
        String sql = "UPDATE fruit SET sell = 1 WHERE id = ?";
        jdbcTemplate.update(sql,request.getId());
    }

    @GetMapping("/api/v1/fruit/stat")
    public FruitSellMoney sellMoney(@RequestParam String name){
        String sql1 = "SELECT SUM(price) FROM fruit WHERE sell = 1 and name = ?";
        long salesAmount = jdbcTemplate.queryForObject(sql1, Long.class, name);
        String sql2 = "SELECT SUM(price) FROM fruit WHERE sell = 0 and name = ?";
        long notSalesAmount = jdbcTemplate.queryForObject(sql2, Long.class, name);

        return new FruitSellMoney(salesAmount, notSalesAmount);
    }
}
