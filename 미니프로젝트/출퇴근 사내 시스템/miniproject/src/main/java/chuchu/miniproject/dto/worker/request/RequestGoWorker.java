package chuchu.miniproject.dto.worker.request;

import java.time.LocalDate;

public record RequestGoWorker(Long workerId, LocalDate workDate, Integer workingMinutes) {

}
