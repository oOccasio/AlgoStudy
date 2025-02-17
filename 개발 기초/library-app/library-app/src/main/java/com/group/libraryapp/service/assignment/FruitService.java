package com.group.libraryapp.service.assignment;

import com.group.libraryapp.dto.assignment.request.FruitInformationRequest;
import com.group.libraryapp.dto.assignment.request.FruitUpdateRequest;
import com.group.libraryapp.dto.assignment.response.FruitSellMoney;
import com.group.libraryapp.repository.assignment.FruitMemoryRepository;
import org.springframework.stereotype.Service;

@Service
public class FruitService {

    private FruitMemoryRepository fruitMemoryRepository;

    public FruitService(FruitMemoryRepository fruitMemoryRepository) {
        this.fruitMemoryRepository = fruitMemoryRepository;
    }

    public void fruitSave(FruitInformationRequest fruitInformationRequest) {
        fruitMemoryRepository.fruitSave(fruitInformationRequest);
    }
    public void fruitUpdate(FruitUpdateRequest fruitUpdateRequest) {
        fruitMemoryRepository.fruitUpdate(fruitUpdateRequest);
    }

    public FruitSellMoney sellMoney(String name){
        return fruitMemoryRepository.sellMoney(name);
    }
}
